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

class TextQuery {
    // as before
public:
    // typedef to make declarations easier
    typedef std::string::size_type str_size;
    typedef std::vector<std::string>::size_type line_no;

    /* interface:
     *    read_file builds internal data structures for the given file
     *    run_query finds the given word and returns set of lines on which it appears
     *    text_line returns a requested line from the input file
    */
    void read_file(std::ifstream &is) 
               { store_file(is); build_map(); }
    std::set<line_no> run_query(const std::string&) const; 
    std::string text_line(line_no) const;
    str_size size() const { return lines_of_text.size(); }
    void display_map();        // debugging aid: print the map

private:
    // utility functions used by read_file
    void store_file(std::ifstream&); // store input file
    void build_map(); // associated each word with a set of line numbers

    // remember the whole input file
    std::vector<std::string> lines_of_text; 

    // map word to set of the lines on which it occurs
    std::map< std::string, std::set<line_no> > word_map;  
    // characters that constitute whitespace
    static std::string whitespace_chars;     
    // canonicalizes text: removes punctuation and makes everything lower case
    static std::string cleanup_str(const std::string&);
};
#endif
