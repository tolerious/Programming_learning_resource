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
using std::cout; using std::endl; using std::cin;
#include <string>
using std::string;

template <class T> T min(T a, T b) 
{
    return a < b ? a : b;
}


// swap parameter values
template <typename T> 
inline
void swap(T& val1, T& val2)
{
    T tmp = val1;
    val1 = val2;
    val2 = tmp;
}

int main()
{
    string s1("hello"), s2("world"), s3("hiya");
    cout << s1 << " " << s2 << endl;  // print hello world
    swap(s1, s3);
    cout << s1 << " " << s2 << endl;  // print hiya world

    double d1 = 3.14, d2 = 2.7, d3 = 1.4;
    cout << d1 << " " << d2 << endl;  // print 3.14 2.7
    swap(d3, d2);
    cout << d1 << " " << d3 << endl;  // print 3.14 2.7

{
    short s1, s2;
    int i1, i2;
    cin >> s1 >> s2;
    cin >> i1 >> i2;
    min(i1, i2);    // ok: instantiate min(int, int)
    min(s1, s2);    // ok: instantiate min(short, short)
    // now print the results
    cout << min(i1, i2) << endl;    
    cout << min(s1, s2) << endl;
}
    return 0;
}
