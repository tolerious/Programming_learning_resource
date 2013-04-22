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

/* Note: This code is an example of *bad* style and serves 
 * only to illustrate the issues involved:
 *
 * First: overloading between int and unsigned often leads to ambiguities
 * Second: relying on the promotion type of an enumeration to determine
 *         which function is matched is inherently machine-dependent.
 * A better design would include a specific 'format' function that took
 * an argument of type 'e2'
*/

#include <string>
using std::string;

enum e1 {a1, b1, c1};
enum e2 {a2, b2, c2=0x80000000};

string format(int);
string format(unsigned int);

enum Stat {Fail, Pass};

void ff(int);
void ff(char);

int main() {
    // ok: enumeration constant Pass promoted to int
    ff(Pass);  // ff(int)
    ff(0);     // ff(int)

    void ff(Stat);
    ff(Fail);  // ff(Stat)

    string s1 = format(a1); // calls format(int)
    string s2 = format(a2); // calls format(unsigned int)

    return 0;
}

#include <iostream>
using std::cout; using std::endl;
void ff(int) { cout << "ff(int)" << endl; }

void ff(char) { cout << "ff(char)" << endl; }

void ff(Stat) { cout << "ff(Stat)" << endl; }

string format(int) { cout << "format(int)" << endl; return ""; }

string format(unsigned int) { cout << "format(unsigned int)" << endl; 
				return ""; }

