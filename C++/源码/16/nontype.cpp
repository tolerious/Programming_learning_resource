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
#include <cstddef>
using std::size_t;

template <class T, size_t N> size_t arr_sz(T (&parm)[N])
{
    return N;
}


// initialize elements of an array to zero
template <class T, size_t N> void array_init(T (&parm)[N]) 
{ 
    for (size_t i = 0; i != N; ++i) {
        parm[i] = 0;
    }
    cout << "calling arr_sz " << arr_sz(parm) << endl;
}

int main()
{
    int x[42]; 
    double y[10];
    array_init(x);  // instantiates array_init(int(&)[42]
    array_init(y);  // instantiates array_init(double(&)[10]
    for (size_t i = 0; i != 42; ++i)
        cout << x[i] << " ";
    cout << endl;
}

void f() {
    int x[42];
    const int sz = 40;
    int y[sz + 2];
    array_init(x);  // instantiates array_init(int(&)[42])
    array_init(y);  // equivalent instantiation
}
