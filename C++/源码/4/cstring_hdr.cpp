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
using std::string;
#include <iostream>
using std::cout; using std::endl;
#include <cstring>

int main() {
    const char *cp1 = "A string example";
    const char *cp2 = "A different string";

    int i = strcmp(cp1, cp2);    // i is positive
    i = strcmp(cp2, cp1);        // i is negative
    i = strcmp(cp1, cp1);        // i is zero

    cout << strlen(cp1) << endl; // prints 16; strlen ignores the null

    if (cp1 < cp2)  // compares addresses, not the values pointed to
     ;

    char ca[] = {'C', '+', '+'};  // not null-terminated
    cout << strlen(ca) << endl;   // disaster: ca isn't null-terminated
                                  // behavior of this print statement is undefined

    // Dangerous: What happens if we miscalculate the size of largeStr?
    char largeStr[16 + 18 + 2]; // will hold cp1 a space and cp2
    strcpy(largeStr, cp1);      // copies cp1 into largeStr
    strcat(largeStr, " ");      // adds a space at end of largeStr
    strcat(largeStr, cp2);      // concatenates cp2 to largeStr
    // prints A string example A different string
    cout << largeStr << endl;       

    // Somewhat safer: use the ``strn'' versions to copy and concatenate
{
    char largeStr[16 + 18 + 2]; // to hold cp1 a space and cp2
    strncpy(largeStr, cp1, 17); // size to copy includes the null
    strncat(largeStr, " ", 2);  // pedantic, but a good habit
    strncat(largeStr, cp2, 19); // adds at most 18 characters, plus a null
    cout << largeStr << endl;       
}

    // Best approach: use strings not char arrays!
{
    string largeStr = cp1; // initialize largeStr as a copy of cp1
    largeStr += " ";       // add space at end of largeStr
    largeStr += cp2;       // concatenate cp2 onto end of largeStr
    cout << largeStr << endl;       
}

    return 0;
}
