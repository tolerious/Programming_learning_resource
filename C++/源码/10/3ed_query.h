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

#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

/*
 * This version of the TextQuery class is more complicated than
 * the one presented in the 4th Edition and is derived from the
 * version presented in the 3rd Edition.
 *
 * It keeps track of character position as well as line number.
 * It also processes the text and query words to:
 *    strips suffixes and 
 *    ignore common words that occur too frequently to bother with.
 *
 * However, we have updated this version to use the standard library
 * facilities, thus making is simpler than the version presented in
 * the 3rd edition of the Primer.  Its basic structure is similar to
 * the version presented in the current edition.
*/
class TextQuery {
public:
    // typedef to make declarations easier
    typedef std::string::size_type str_size;
    typedef std::vector<std::string>::size_type line_no;
    typedef std::pair<line_no,str_size> location;

    /* interface:
     *    read_file builds internal data structures for the given file
     *    run_query finds the given word and returns set of lines on which it appears
     *    text_line returns a requested line from the input file
    */
    void read_file(std::ifstream &is) 
               { store_file(is); build_map(); }

    std::vector<location> run_query(const std::string&); 
    std::string text_line(line_no line) { return lines_of_text[line]; }
    str_size size() const { return lines_of_text.size(); }
    void display_map();                  // debugging aid: print the map

private:
    void store_file(std::ifstream&);  // read and store input file
    void build_map();                  // build map of each word in file

    // used by store words, ignore adjacent whitespace
    str_size skip_whitespace(const std::string&, str_size);

    // test word and if not an excluded word update map 
    void test_insert(const std::string&, str_size, str_size, line_no);

    bool exclude_word(const std::string&); // test for excluded words

    void strip_caps(std::string&);         // make lower case
    void strip_punct(std::string&);        // remove punctuation
    void strip_suffixes(std::string&);     // remove common suffixes

    void suffix_s(std::string&);           // remove suffixes ending in s
    int chk_ending(const std::string&, const char*); //used by suffix_s

    // populate exclusion_set with words to ignoare
    // Chapter 13 discusses static class members
    static std::set<std::string> build_exclusion_set(); 

private:
    // remember the whole input file
    std::vector<std::string> lines_of_text; 

    // map word to vector of all the line/char positions on which it occurs
    std::map< std::string, std::vector<location> > word_map;  

    // set of words to ignore
    static std::set<std::string> exclusion_set;

    // characters that constitute whitespace
    static std::string whitespace_chars;     
};
#endif
