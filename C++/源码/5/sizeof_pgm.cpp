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
#include "Sales_item.h"
using std::cout;
using std::endl;


int main() 
{
    Sales_item item, *p;

    // three ways to obtain size required to hold an object of type Sales_item
    sizeof(Sales_item); // size required to hold an object of type Sales_item 
    sizeof item; // size of item's type, e.g., sizeof(Sales_item)
    sizeof *p;   // size of type to which p points, e.g., sizeof(Sales_item)

    cout << "short: " << sizeof(short) << "\n"
         << "short[3]: " << sizeof(short[3]) << "\n"
         << "short*: " << sizeof(short*) << "\n"
         << "short&: " << sizeof(short&) << endl;

    cout << endl; // to separate output

    cout << "Sales_item: " << sizeof(Sales_item) << "\n"
         << "Sales_item[3]: " << sizeof(Sales_item[3]) << "\n"
         << "Sales_item*: " << sizeof(Sales_item*) << "\n"
         << "Sales_item&: " << sizeof(Sales_item&) << endl;

// Differentiate use of sizeof array and sizeof on a pointer:
// First output statement will print 10; second prints 1
// The first statement divides size of entire array by size of an element
// The second divides size of a pointer by the size of an int
{
    int x[10];   int *p = x;

    cout << sizeof(x)/sizeof(*x) << endl;
    cout << sizeof(p)/sizeof(*p) << endl;
}
    return 0;
}
