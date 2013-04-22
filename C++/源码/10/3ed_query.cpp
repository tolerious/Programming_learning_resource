/*
 * This file contains code from "C++ Primer, Fourth Edition", by Stanley B.
 * Lippman, Jose Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2005 by Objectwrite, Inc., Jose Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Contracts Department
 * 	75 Arlington Street, Suite 300
 * 	Boston, MA 02216
 * 	Fax: (617) 848-7047
*/ 

#include "3ed_query.h"
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using std::set;
using std::string;
using std::getline;
using std::map;
using std::vector;
using std::cerr;
using std::cout;
using std::cin;
using std::ifstream;
using std::endl;
using std::pair;
using std::make_pair;
using std::ispunct;
using std::tolower;
using std::strlen;

// read input file: store each line as element in lines_of_text 
void TextQuery::store_file(ifstream &is)
{
    string textline;
    while (getline(is, textline))
       lines_of_text.push_back(textline);
}
set<string> TextQuery::exclusion_set = build_exclusion_set();

// \v: vertical tab; \f: formfeed; \r: carriage return are
// treated as whitespace characters along with space, tab and newline
string TextQuery::whitespace_chars(" \t\n\v\r\f");

// finds the whitespace separated words in the input vector
// then puts them in a cannonical form: eliminate suffixes,
// make lowercase etc. Finally, test if its an excluded word or not.
// If not excluded store the word in word_map along with
// its location (line # and character position) info
void TextQuery::build_map()
{
    // process each line from the input vector
    for (line_no line_num = 0; 
                 line_num != lines_of_text.size();
                 ++line_num)
    {
        string textline = lines_of_text[line_num];
        if (textline.empty()) continue; //ignore blank lines

        // make line lower case and remove extraneous punctuation
        strip_caps(textline);
        strip_punct(textline);

        /* 
         * Because we want to keep track of position as well as
         * line number, we have to process the line a character at a time.
         * We can't use an istringstream to read the words.
         * prev_pos will denote first character in each word,
         * pos will denote whitespace that separates the word from the next
         * initially pos denotes first non-whitespace at beginning of line
        */
        str_size pos = skip_whitespace(textline, 0), prev_pos = pos;

        // find each whitespace separated word
        while ((pos = textline.find_first_of(whitespace_chars, pos)) 
                   != string::npos)
        {
            // remove suffixes and put the word into the map if apporpriate
            test_insert(textline, prev_pos, pos, line_num);

            // if there's more text to process, increment pos to get next char
            if (pos != textline.size())
                ++pos;  
            // read and discard adjacent spaces, if any, updating prev_pos too
            pos = prev_pos = skip_whitespace(textline, pos);
        }

        // don't forget last word in the line
        if (pos != prev_pos)  // false if line ends in whitespace
            test_insert(textline, prev_pos, pos, line_num);
    }
}

TextQuery::str_size 
TextQuery::skip_whitespace(const string &line, str_size pos)
{
    // ignore adjacent whitespace
    str_size next = line.find_first_not_of(whitespace_chars, pos);
    if (next != string::npos)
        return next;
    else
        return line.size();
}

void TextQuery::test_insert(const string &line, str_size prev_pos, 
                  str_size pos, line_no line_num)
{
    // make copy of the whitespace delimited word
    string word(line.substr(prev_pos, pos - prev_pos));

    strip_suffixes(word); // last of the cleanup operations

    // if there's anything left after stripping punctuation 
    // and it's not an excluded word, add to the map
    // appending line num & char pos to vector for this word
    if (!word.empty() && !exclude_word(word))
         word_map[word].push_back(make_pair(line_num,prev_pos));

    return;
}

void TextQuery::strip_suffixes(string &word)
{
     if (word.size() <= 3)    // too short to have any suffixes
            return;

     if (word[word.size() - 1] == 's')  // only handle plurals so far
             suffix_s(word);

     // additional suffix handling goes here
}

void TextQuery::suffix_s(string &word)
{
    // some words ending in s aren't suffixes, they're part of the word
    static char* ok_endings[] = {"ous", "ius", "ss", "is"};
    size_t sz = sizeof(ok_endings)/sizeof(char*);  // how many elements?
    for (size_t i = 0; i != sz; ++i)
        if (chk_ending(word, ok_endings[i]) == 0)
              return;

    // replace common suffixes by their base word ending
    // repl_endings first dimension is the ending we'll remove
    //              second dimension is the new ending we'll insert
    static char* repl_endings[][2] = 
          { {"ies", "y"}, {"ses", "s"}, {"\'s", ""}, {"s", ""} };

    sz = sizeof(repl_endings)/(sizeof(char*) * 2);  // two-dimensions
    for (size_t i = 0; i != sz; ++i) 
        if (chk_ending(word, repl_endings[i][0]) == 0) {
           size_t sz = strlen(repl_endings[i][0]);
           word.replace(word.size() - sz, sz, repl_endings[i][1]);
           return;
        }
}

// compare end of the word with the ending we're given
int TextQuery::chk_ending(const string &word, const char *ending)
{
    size_t sz = strlen(ending);
    return word.compare(word.size() - sz, sz, ending);
}

void TextQuery::strip_caps(string &line)
{
    // not changing the size of line, so safe to cache the size
    str_size sz = line.size();
    for (str_size pos = 0; pos != sz; ++pos)
        line[pos] = tolower(line[pos]);
}

// except for apostrophe, replace punctuation by a space
// apostrophe is special: it might precede by 's, which is a suffix
void TextQuery::strip_punct(string &line)
{
    for (str_size pos = 0; pos != line.size(); ++pos)
        if (ispunct(line[pos])) {
             if (line[pos] != '\'') line[pos] = ' ';
        }
}

// this function should be changed to let the user specify a
// file of words to ignore, but for now, we'll keep it simple
// and assume a specific file
set<string> TextQuery::build_exclusion_set()
{
    set<string> ret;
    ifstream infile("exclusion_set");
    if (!infile)
    {
        static string default_excluded_words[] = {
          "the","and","but","that","then","are","been",
          "can","can't","cannot","could","did","for",
          "had","have","him","his","her","its","into",
          "were","which","when","with","would"
         };

        cerr << "warning! unable to open word exclusion file! -- "
            << "using default set" << endl;

        ret = set<string>(default_excluded_words, 
                          default_excluded_words + 
                          sizeof(default_excluded_words)/sizeof(string));
    } else {
        string word;
        while (infile >> word) ret.insert(word);
    }
    return ret;
}

bool TextQuery::exclude_word(const string &word)
{
    return (exclusion_set.find(word) != exclusion_set.end());
}

vector<TextQuery::location> TextQuery::run_query(const string &s)
{
    // make local copy so we can clean it up to match words
    // entered in the map; but when communicate back to the
    // user always use their original version
    string sought = s;  
    strip_caps(sought);
    strip_punct(sought);
    strip_suffixes(sought);

    // Note: must use find and not subscript the map directly
    // Subscripting a map adds the element if it's not already there
    // We want to know whether the element was there to begin with
    if (word_map.find(sought) == word_map.end())
         return vector<location>();  // not found, return empty location vector
    else
        // fetch list of locations for this word
        return word_map[sought];

}

void TextQuery::display_map()
{
    typedef map< string,vector<location> > map_text;
    map_text::iterator iter = word_map.begin(),
                   iter_end = word_map.end();

    // Note: map iter returns index, value pair
    // so iter->first is the index word, 
    // iter->second the vector of its locations

    // for each word in the map
    while (iter != iter_end) {
        cout << "word: " << iter->first << " {";

        vector<location> text_locs = iter->second;
        vector<location>::iterator liter = text_locs.begin(),
                               liter_end = text_locs.end();

        // print all (line,char) locations for this word
        // because this is a debugging routine, don't adjust
        // line/pos numbers.  As normal for programmers, start from 0
        while (liter != liter_end)
        {
            cout << "(" << liter->first
                 << "," << liter->second << ")";

            if (++liter != liter_end)
                 cout << ", ";

         }

         cout << "}\n";  // end list of output this word
         ++iter;         // get next word in the map
    }
    cout << endl;  // finished printing entire map
}
