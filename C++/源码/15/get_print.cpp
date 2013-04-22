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

#include "Query.h"
#include "TextQuery.h"
#include <string>
#include <set>
#include <iostream>
#include <fstream>

using std::set;
using std::string;
using std::cerr;
using std::cout;
using std::cin;
using std::ifstream;
using std::endl;

TextQuery build_textfile(const string &filename)
{
    // get a file to read from which user will query words
    ifstream infile;
    if (!open_file(infile, filename)) {
        cerr << "No input file!" << endl;
        return TextQuery();
    }

    TextQuery ret;
    ret.read_file(infile);  // builds query map
    return ret;  // builds query map
}

bool get_word(string &s1)
{
    cout << "enter a word to search for, or q to quit: ";
    cin >> s1;
    if (!cin || s1 == "q") return false;
    else return true;
}

bool get_words(string &s1, string &s2)
{

    // iterate with the user: prompt for a word to find and print results
    cout << "enter two words to search for, or q to quit: ";
    cin  >> s1;

    // stop if hit eof on input or a "q" is entered
    if (!cin || s1 == "q") return false;
    cin >> s2;
    return true;
}

void print_results(const set<TextQuery::line_no>& locs, const TextQuery &file)
{
    // report no matches
    if (locs.empty()) {
        cout << "\nSorry. There are no entries for your query." 
             << "\nTry again." << endl;
        return;
    }

    // if the word was found, then print count and all occurrences
    set<TextQuery::line_no>::size_type size = locs.size();
    cout << "match occurs " 
         << size << (size == 1 ? " time:" : " times:") << endl;

    // print each line in which the word appeared
    set<TextQuery::line_no>::const_iterator it = locs.begin();
    for ( ; it != locs.end(); ++it) {
        cout << "\t(line "
             // don't confound user with text lines starting at 0
             << (*it) + 1 << ") "
             << file.text_line(*it) << endl;
    }
}
