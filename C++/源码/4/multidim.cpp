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
using std::cout;
using std::endl;

    int ia[3][4];      // array of size 3, each element is an array of ints of size 4 

int main()
{
    // row 0 is explicitly initialized; other elements implicitly 0
    int ix[3][4] = {0, 3, 6, 9};
    cout << ix[0][3] << " " << ix[1][0] << " " << ix[2][0] << endl; //prints 9 0 0
    const size_t rowSize = 3;
    const size_t colSize = 4;
    int ia[rowSize][colSize];   // 12 uninitialized elements 

    // for each row
    for (size_t i = 0; i != rowSize; ++i)     
        // for each column within the row
        for (size_t j = 0; j != colSize; ++j) 
            // initialize to its positional index
            ia[i][j] = i * colSize + j;   

    cout << ia[0][0] << " " 
         << 
            ia[2][3] // fetches last element from the array in the last row
         << endl;  // prints 0 11
    // prints garbage: mising second dimension so this statement prints a pointer
    cout << ia[0] << " "  << endl;  

    int (*ip)[4] = ia; // ip points to an array of 4 ints
    ip = &ia[2];       // ia[2] is an array of 4 ints
{
    typedef int int_array[4];
    int_array *ip = ia;

    // use pointers to print the contents of the array
    for (int_array *p = ia; p != ia + 3; ++p)
        for (int *q = *p; q != *p + 4; ++q)
             cout << *q << endl;
}
    cout << ia[0][0] << " " 
         << ia[2][3] // fetches last element from the array in the last row
         << endl;  // prints 0 11
    return 0;
}
