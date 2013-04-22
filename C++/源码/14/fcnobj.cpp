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

#include <functional>
using std::plus; using std::negate;

#include <iostream>
using std::cout; using std::endl;

#include <vector>
#include <algorithm>
using std::count_if; using std::bind2nd; using std::not1; using std::ptr_fun;
using std::less_equal; using std::vector;

#include <iostream>
using std::cin;

#include <string>
using std::string;

bool size_compare(string s, string::size_type sz)
{
    return s.size() >= sz;
}

int main() {

    cout << plus<int>()(3,4) << endl; // prints 7

    plus<int> intAdd;        // function object that can add two int values
    negate<int>  intNegate;  // function object that can negate an int value

    // uses intAdd::operator(int, int) to add 10 and 20
    int sum = intAdd(10, 20);        // sum = 30

    cout << sum << endl;

    // uses intNegate::operator(int) to generate -10 as second parameter
    // to intAdd::operator(int, int)
    sum = intAdd(10, intNegate(10));  // sum = 0

    cout << sum << endl;

    int arry[] = {0,1,2,3,4,5,16,17,18,19};

    vector<int> vec(arry, arry + 10);

    cout <<
    count_if(vec.begin(), vec.end(),
             bind2nd(less_equal<int>(), 10));
    cout << endl;

    cout <<
    count_if(vec.begin(), vec.end(),
             not1(bind2nd(less_equal<int>(), 10)));
    cout << endl;

    return 0;
}
