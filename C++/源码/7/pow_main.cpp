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

/*
 * Note -- this function duplicates the functionality of the
 * 'pow' function in the <cmath> header.  However, it has an
 * important limitation: It does integer calculations and so
 * is more likely to overflow than the library version that 
 * does its computations in floating point.
 * 
 * As usual, it is better to use the library function than one
 * of our own.  The library defines six overloaded versions of
 * pow: pow(float, int), pow(float, float), pow(double, int),
 * pow(double, double), pow(long double, int) and pow(long double, long double)
*/
extern int power(int,int);

#include <iostream>
using std::cout; using std::endl;
#include <cmath>
using std::pow;

int main()
{
    cout << power(2, 10) << endl;
    cout << power(2, 16) << endl;
    // using our integer based power, this call likely to overflow
    cout << power(10, 10) << endl;  

    // use the library instead:  
    // Note we must change the first argument to be a double 
    // otherwise the call would be ambiguous and would not compile
    cout << pow(2.0, 10) << endl;
    cout << pow(2.0, 16) << endl;
    cout << pow(10.0, 10) << endl;  // should not overflow

    return 0;
}
