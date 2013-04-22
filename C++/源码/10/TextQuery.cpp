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

#include "TextQuery.h"
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <stdexcept>

using std::istringstream;
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
using std::ispunct;
using std::tolower;
using std::strlen;
using std::out_of_range;

string TextQuery::text_line(line_no line) const
{
    if (line < lines_of_text.size())
        return lines_of_text[line];
    throw std::out_of_range("line number out of range");
}

// read input file: store each line as element in lines_of_text 
void TextQuery::store_file(ifstream &is)
{
    string textline;
    while (getline(is, textline))
       lines_of_text.push_back(textline);
}

// \v: vertical tab; \f: formfeed; \r: carriage return are
// treated as whitespace characters along with space, tab and newline
string TextQuery::whitespace_chars(" \t\n\v\r\f");

// finds whitespace-separated words in the input vector
// and puts the word in word_map along with the line number
void TextQuery::build_map()
{
    // process each line from the input vector
    for (line_no line_num = 0; 
                 line_num != lines_of_text.size();
                 ++line_num)
    {
        // we'll use line to read the text a word at a time
        istringstream line(lines_of_text[line_num]);
        string word;
        while (line >> word)
            // add this line number to the set;
            // subscript will add word to the map if it's not already there
            word_map[cleanup_str(word)].insert(line_num);
    }
}

set<TextQuery::line_no>
TextQuery::run_query(const string &query_word) const
{
    // Note: must use find and not subscript the map directly
    // to avoid adding words to word_map!
    map<string, set<line_no> >::const_iterator 
                          loc = word_map.find(cleanup_str(query_word));
    if (loc == word_map.end()) 
        return set<line_no>();  // not found, return empty set
    else
        // fetch and return set of line numbers for this word
        return loc->second;
}

void TextQuery::display_map()
{
    map< string, set<line_no> >::iterator iter = word_map.begin(),
                                       iter_end = word_map.end();

    // for each word in the map
    for ( ; iter != iter_end; ++iter) {
        cout << "word: " << iter->first << " {";

        // fetch location vector as a const reference to avoid copying it
        const set<line_no> &text_locs = iter->second;
        set<line_no>::const_iterator loc_iter = text_locs.begin(),
                                     loc_iter_end = text_locs.end();

        // print all line numbers for this word
        while (loc_iter != loc_iter_end)
        {
            cout << *loc_iter;

            if (++loc_iter != loc_iter_end)
                 cout << ", ";

         }

         cout << "}\n";  // end list of output this word
    }
    cout << endl;  // finished printing entire map
}

string TextQuery::cleanup_str(const string &word)
{
    string ret;
    for (string::const_iterator it = word.begin(); it != word.end(); ++it) {
        if (!ispunct(*it))
            ret += tolower(*it);
    }
    return ret;
}

