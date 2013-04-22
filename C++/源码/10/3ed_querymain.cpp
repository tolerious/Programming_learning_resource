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
using std::map;
using std::vector;
using std::cerr;
using std::cout;
using std::cin;
using std::ifstream;
using std::endl;
using std::pair;
using std::make_pair;

ifstream& open_file(ifstream&, const string&);
int main(int argc, char **argv)
{

    if (argc != 2) {cerr << "No input file" << endl; return -2;}

    // get a file to read from which user will query words
    ifstream infile;
    if (!open_file(infile, argv[1])) {
        cerr << "No input file!" << endl;
        return -1;
    }
    TextQuery tq;
    tq.read_file(infile);  // builds query map

    // iterate with the user: prompt for a word to find and print results
    string sought;
    do {
        cout << "enter a word against which to search the text.\n"
             << "to quit, enter a single character ==>  ";
        cin  >> sought;

        // stop if hit eof on input or single character entered
        if (!cin || sought.size() < 2) break;

        // find all the occurrences of the users requested string
        vector<TextQuery::location> locs = tq.run_query(sought);

        // report no matches
        if (locs.empty()) {
            cout << "\nSorry. There are no entries for " 
                 << sought << ".\nTry again." << endl;
            continue;
        }
    
        // if the word was found, then print count and all occurrences
        vector<TextQuery::location>::size_type size = locs.size();
        cout << "\n" << sought << " occurs " << size
             << (size == 1 ? " time:" : " times:")
             << "\n" << endl;
    
        // print each line in which the word appeared
        vector<TextQuery::location>::iterator it = locs.begin();
        while (it != locs.end()) {
            cout << "\t(line: "
                 // don't confound user with text lines starting at 0
                 << it->first + 1 << ", pos: " << it->second + 1 << ") "
                 << tq.text_line(it->first) << endl;
            ++it;
         }
    } while (!sought.empty());

    cout << "Ok, bye!" << endl;

    // debugging aid -- look at the map that was built
    tq.display_map();
    return 0;
}
