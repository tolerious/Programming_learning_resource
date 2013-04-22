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

#include <iostream>
using std::cout; using std::endl;

#include "MS_Queue.h"

Queue<int> queue1;

int main() 
{
    for (int ix = 0; ix != 1024; ++ix)
        queue1.push(ix);
    
    for (int ix = 0; ix != 1024; ++ix) {
        int i = queue1.front();  // check next item
        if (i != ix)
             cout << "Something's wrong! i = " << i
                  << " ix = " << ix << endl;
        queue1.pop();   // and remove it
    }

    if (!queue1.empty())
        cout << "Queue is not empty but should be!" << endl;
    else
        cout << "OK, queue empty again" << endl;


    for (int ix = 0; ix != 1024; ++ix)
        queue1.push(ix);

    Queue<int> queue2(queue1);  // use copy constructor

    for (int ix = 0; ix != 1024; ++ix) {
        int i = queue2.front();   // check next item
        if (i != ix)
             cout << "Something's wrong! i = " << i
                  << " ix = " << ix << endl;
        queue2.pop();  // and remove it
    }

    if (!queue2.empty())
        cout << "queue2 is not empty but should be!" << endl;
    else
        cout << "OK, queue2 empty again" << endl;

    queue2 = queue1;  // use asssignment operator
    for (int ix = 0; ix != 1024; ++ix) {
        int i = queue2.front();
        if (i != ix)
             cout << "Something's wrong! i = " << i
                  << " ix = " << ix << endl;
        queue2.pop();
    }

    if (!queue2.empty())
        cout << "queue2 is not empty but should be!" << endl;
    else
        cout << "OK, queue2 empty again" << endl;
    
}
