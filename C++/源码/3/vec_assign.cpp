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

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<int> ivec(10);

    // reset all the elements in ivec to 0
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix)
            ivec[ix] = 0;

    // print what we've got so far: should print 10 0's
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix)
            cout << ivec[ix] << " ";
    cout << endl;

    // equivalent loop using iterators to reset all the elements in ivec to 0
    for (vector<int>::iterator iter = ivec.begin();
                               iter != ivec.end(); ++iter)
	    *iter = 0;  // set element to which iter refers to 0

    // print using iterators: should print 10 0's
    for (vector<int>::iterator iter = ivec.begin();
                               iter != ivec.end(); ++iter)
            cout << *iter << " "; // print the element to which iter refers 
    cout << endl;

    vector<int>::iterator iter = ivec.begin();
    while (iter != ivec.end()) {
            *iter = 0;
            ++iter;
    }
    return 0;
}
