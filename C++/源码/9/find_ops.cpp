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

#include <string>
#include <iostream>
using std::string; using std::cout; using std::endl;

int main() 
{
    string numerics("0123456789");
    string name("r2d2");

    string::size_type pos = name.find_first_of(numerics);
    cout << "found number at index: " << pos 
         << " element is " << name[pos] << endl;

{
    string::size_type pos = 0;  
    // each trip reset pos to the next instance in name
    while ((pos = name.find_first_of(numerics, pos)) 
                  != string::npos) {
        cout << "found number at index: " << pos 
             << " element is " << name[pos] << endl;

        ++pos; // move to the next character
    }
}

    string river("Mississippi");

    string::size_type first_pos = river.find("is");  // returns 1
    string::size_type last_pos = river.rfind("is");  // returns 4
    cout << "find returned: " << first_pos 
         << " rfind returned: " << last_pos << endl;

{
    string numbers("0123456789");
    string dept("03714p3");

    // returns 5, which is the index to the character 'p'
    string::size_type pos = dept.find_first_not_of(numbers);
    cout << "first_not returned: " << pos << endl;
}

    return 0;
}

