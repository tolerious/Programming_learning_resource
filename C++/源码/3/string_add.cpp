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
#include <string>

using std::string; using std::cout; using std::endl;

int main() 
{

    string s1("hello, ");
    string s2("world\n");

    string s3 = s1 + s2;   // s3 is hello, world\n
    
    // print what we've got so far
    cout << "s1: " << s1 << " s2: " << s2 << " s3: " << s3 << endl;

    s1 += s2;   // equivalent to s1 = s1 + s2

    // print after update to s1
    cout << "s1: " << s1 << " s2: " << s2 << " s3: " << s3 << endl;

{
    // a better way to ``add'' punctuation
    string s1("hello");
    string s2("world");

    string s3 = s1 + ", " + s2 + "\n";

    // print again, now there won't be a newline after printing s2
    cout << "s1: " << s1 << " s2: " << s2 << " s3: " << s3 << endl;

}
return 0;
}
