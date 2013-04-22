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

#include <deque>
#include <stack>
#include <iostream>

using std::deque;
using std::stack; using std::cout; using std::cerr; using std::endl;

int main()
{
    // number of elements we'll put in our stack
    const stack<int>::size_type stk_size = 10;
    stack<int> intStack;  // empty stack

    // fill up the stack
    int ix = 0;
    while (intStack.size() != stk_size)
        // use postfix increment; want to push old value onto intStack
        intStack.push(ix++);   // intStack holds 0...9 inclusive

    int error_cnt = 0;
    // look at each value and pop it off the stack
    while (intStack.empty() == false) {
        int value = intStack.top();
        // read the top element of the stack
        if (value != --ix) {
            cerr << "oops! expected " << ix 
                 << " received " << value << endl;
            ++error_cnt;
        }
        intStack.pop(); // pop the top element, and repeat
    }
    cout << "Our program ran with " 
         << error_cnt << " errors!" << endl;

    return 0;
}
