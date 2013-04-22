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

#include "seq_preamble.h"

vector<char> c_vec;
//string s("some string"), s2("some other string");
string s, s2;

int main() 
{
    s = "some string";
    s2 = "some other string";
    // 3 equivalent ways to insert all the characters from s2 at beginning of s
    // insert iterator range before s.begin()
    s.insert(s.begin(), s2.begin(), s2.end());  

    cout << "insert iterators version:        " << s << endl;
    s = "some string";

    // insert copy of s2 before position 0 in s
    s.insert(0, s2);                  

    cout << "insert string at given position: " << s << endl;
    s = "some string";

    // insert s2.size() characters from s2 starting at s2[0] before s[0]
    s.insert(0, s2, 0, s2.size());   

    cout << "insert positional version:       " << s << endl;
    s = "";

    c_vec.push_back('a');   // temporary hack to workaround g++ bug

    // replace characters in s by elements from c_vec
    s.insert(s.begin(), c_vec.begin(), c_vec.end());  

    s.insert(s.size(), 5, '!'); // insert five exclamation points at end of s
    cout << s << endl;
    s.erase(s.size() - 5, 5);  // erase last five characters from s
    cout << s << endl;
{
    char *cp = "Stately plump Buck";
    string s;

    s.assign(cp, 7);            // s == "Stately"
    cout << s << endl;
    s.insert(s.size(), cp + 7); // s == "Stately plump Buck"
    cout << s << endl;
}

{
    string s("C++ Primer");         // initialize s to "C++ Primer"
    s.append(" 3rd Ed.");           // s == "C++ Primer 3rd Ed."

    // equivalent to s.append(" 3rd Ed.")
    s.insert(s.size(), " 3rd Ed."); 
    cout << s << endl;

    // starting at position 11, erase 3 characters and then insert "4th"
    s.replace(11, 3, "4th");        // s == "C++ Primer 4th Ed."

    cout << s << endl;

    // equivalent way to replace "3rd" by "4th"
    s.erase(11, 3);                 // s == "C++ Primer Ed."
    s.insert(11, "4th");            // s == "C++ Primer 4th Ed."

    cout << s << endl;

    s.replace(11, 3, "4th");        // s == "C++ Primer 4th Ed."

    cout << s << endl;

    s.replace(11, 3, "Fourth"); // s == "C++ Primer Fourth Ed."
    cout << s << endl;

{
    string s("C++ Primer, 3rd Ed.");
    s.replace(s.find("3rd"), 3, "Fourth");
    cout << s << endl;
}
}
    return 0;
}
