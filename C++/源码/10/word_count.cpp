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
#include <map>

int main() 
{
    // count number of times each word occurs in the input
    map<string, int> word_count;  // empty map from string to int
    string word;
    while (cin >> word)
      ++word_count[word];

    // get iterator positioned on the first element
    map<string, int>::const_iterator 
                            map_it = word_count.begin();
    // for each element in the map
    while (map_it != word_count.end()) {
        // print the element key, value pairs
        cout << map_it->first << " occurs " 
             << map_it->second << " times" << endl;
        ++map_it;  // increment iterator to denote the next element
    }
return 0;
}

// Alternative implementation using insert instead of subscript
void alt_word_count()
{
    // count number of times each word occurs in the input
    map<string, int> word_count;  // empty map from string to int
    string word;

    while (cin >> word) {
        // inserts element with key equal to word and value 1;
        // if word already in word_count, insert does nothing
        pair<map<string, int>::iterator, bool> ret =
                word_count.insert(make_pair(word, 1));
        if (!ret.second)         // word already in word_count
            ++ret.first->second; // increment counter
    }
}
