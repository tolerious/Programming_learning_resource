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

#include "seq_preamble.h"
#include <map>
using std::map;

int main() 
{
    map<string, int> word_count;  // empty map from string to int
    string word;
    while (cin >> word)
      ++word_count[word];

    string removal_word = "the";

    // erase of a key returns number of elements removed
    if (word_count.erase(removal_word))
         cout << "ok: " << removal_word << " removed\n";
    else cout << "oops: " << removal_word << " not found!\n";


    map<string,int>::iterator where;
    where = word_count.find(removal_word);

    if (where == word_count.end())
         cout << "oops: " << removal_word << " not found!\n";
    else {
         word_count.erase(where);   // erase iterator returns void
         cout << "ok: " << removal_word << " removed!\n";
    }
    return 0;
}
