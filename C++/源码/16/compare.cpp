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

#include "tmpl_preamble.h"
#include "Sales_item.h"

// implement strcmp-like generic compare function 
// returns 0 if the values are equal, 1 if v1 is larger, -1 if v1 is smaller
template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

// repeats body of compare but with comments
int f(int v1, int v2)
{
    if (v1 < v2) return -1;  // < on two objects of type T
    if (v2 < v1) return 1;   // < on two objects of type T
    return 0;                // return int;  not dependent on T
}

// special version of compare to handle C-style character strings
template <>
int compare<const char*>(const char* const &v1, 
                         const char* const &v2)
{
    return strcmp(v1, v2);
}

// returns 0 if the values are equal, -1 if v1 is smaller, 1 if v2 is smaller
int compare(const string &v1, const string &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int compare(const double &v1, const double &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int main()
{
    // T is int; 
    // compiler instantiates int compare(const int&, const int&)
    cout << compare(1, 0) << endl;  

    // T is string; 
    // compiler instantiates int compare(const string&, const string&)
    string s1 = "hi", s2 = "world";
    cout << compare(s1, s2) << endl; 
{
    short s1, s2;
    int i1, i2;
    compare(i1, i2);    // ok: instantiate compare(int, int)
    compare(s1, s2);    // ok: instantiate compare(short, short)
}
    char *cp1 = "world", *cp2 = "hi";
    cout << compare(cp1, cp2) << endl;       // compares pointer values!

{
    const char *cp1 = "world", *cp2 = "hi";
    int i1, i2;
    compare(cp1, cp2); // calls the specialization
    compare(i1, i2);   // calls the generic version instantiated with int
}
{
    const char *cp1 = "world", *cp2 = "hi";
    compare<string>(cp1, cp2);  // converts arguments to string
}
    return 0;
}

