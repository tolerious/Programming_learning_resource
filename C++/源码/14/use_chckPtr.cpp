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

#include "CheckedPtr.h"
#include <iostream>
using std::cout; using std::endl;
#include <exception>
using std::exception;

int main()
{
    int ia[] = {1,2,3,4,5,6,7,8,9};
    const int size = sizeof(ia)/sizeof(int);

    CheckedPtr p1(ia, ia + size);

    CheckedPtr parr(ia, ia + size);  // ia points to an array of ints
    parr.operator++(0);              // call postfix operator++
    parr.operator++();               // call prefix  operator++

    try {
        int i = 0;
        while(i++ != size)
          cout << *p1++ << endl;
    } catch (exception& e) { cout << e.what() << endl; }
    //p1 now positioned one past end of array

    // should throw dereference error
    try { *p1; } catch (exception &e) {cout << e.what() << endl; }

    // should throw increment error
    try { p1++; } catch (exception &e) {cout << e.what() << endl; }
    try { ++p1; } catch (exception &e) {cout << e.what() << endl; }

    cout << endl;

    try {
        int i = size; --p1; // reset p1 to denote last element
        while(i-- > 1)
          cout << *p1-- << endl;
        cout << *p1 << endl;
    } catch (exception& e) { cout << e.what() << endl; }
    //p1 now positioned at beginning of array

    cout << endl;

    // repeat using prefix ops
    try {
        int i = 0;
        cout << *p1 << endl;
        while(i++ != size-1)
          cout << *++p1 << endl;
    } catch (exception& e) { cout << e.what() << endl; }
    // p1 now positioned on end of array

    cout << endl;

    try {
        int i = size; ++p1;  // now positioned one past end
        while(i-- > 0)
          cout << *--p1 << endl;
    } catch (exception& e) { cout << e.what() << endl; }
    // p1 now positioned at beginning of array

    // should throw decrement error
    try { --p1; } catch (exception &e) {cout << e.what() << endl; }
    try { p1--; } catch (exception &e) {cout << e.what() << endl; }

    return 0;
}

