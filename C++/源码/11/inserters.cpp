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

#include "algs_preamble.h"

int main() 
{

    list<int> ilst, ilst2, ilst3;     // empty lists

    // after this loop ilst contains: 1 2 3 4
    for (list<int>::size_type i = 0; i != 4; ++i)
         ilst.push_front(i);

    // print list to see the ordering
    cout << "ilst" << endl;
    for (list<int>::iterator iter = ilst.begin(); iter != ilst.end(); ++iter)
	    cout << *iter << " ";
    cout << endl;

    // after copy ilst2 contains: 4 3 2 1
    copy(ilst.begin(), ilst.end(), front_inserter(ilst2));

    // after copy, ilst3 contains: 1 2 3 4
    copy(ilst.begin(), ilst.end(), 
                inserter(ilst3, ilst3.begin()));

    // print ilst2 and ilst3 
    cout << "ilst2" << endl;
    for (list<int>::iterator iter = ilst2.begin(); iter != ilst2.end(); ++iter)
	    cout << *iter << " ";
    cout << endl;
    cout << "ilst3" << endl;
    for (list<int>::iterator iter = ilst3.begin(); iter != ilst3.end(); ++iter)
	    cout << *iter << " ";
    cout << endl;

    return 0;
}
