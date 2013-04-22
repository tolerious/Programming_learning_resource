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

#include "assoc_preamble.h"
#include "seq_preamble.h"
#include <fstream>
using std::ifstream;

void restricted_wc(ifstream &remove_file,
                   map<string, int> &word_count)
{
    set<string> excluded;   // set to hold words we'll ignore
    string remove_word;
    while (remove_file >> remove_word)
        excluded.insert(remove_word);

    // print contents of the word exclusion set
    for (set<string>::iterator set_it = excluded.begin();
                               set_it != excluded.end();
                               ++set_it)
         cout << *set_it << endl;

    // read input and keep a count for words that aren't in the exclusion set
    string word;
    while (cin >> word)
       // increment counter only if the word is not in excluded
       if (!excluded.count(word))
            ++word_count[word];
}

// call with the name of the exclusion set file
int main(int argc, char **argv) 
{
    ifstream remove_file;
    open_file(remove_file, argv[1]);  // file of words to ignore
    map<string, int> word_count;
    restricted_wc(remove_file, word_count);
    // get iterator positioned on the first element
    map<string, int>::iterator map_it = word_count.begin();
    // for each element in the map
    while (map_it != word_count.end()) {
        // print the element key, value pairs
        cout << map_it->first << " occurs "
             << map_it->second << " times" << endl;
        ++map_it;  // increment iterator to denote the next element
    }
    return 0;
}

