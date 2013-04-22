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

#include <stdexcept>
#include <cstddef>
#include <list>
using std::list;
#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;

class SmallInt {
public:
    SmallInt(int i = 0): val(i)
    { if (i < 0 || i > 255)
        throw std::out_of_range("Bad SmallInt initializer");
    }
    operator int() { return val; }
private:
    std::size_t val;
};

#include "MS_Queue.h"

int main()
{
    short a[4] = { 0, 3, 6, 9 };
    // instantiates Queue<int>::Queue(short *, short *)
    Queue<int> qi(a, a + 4);  // copies elements from a into qi
    cout << qi << endl;


    vector<int> vi(a, a + 4);
    // instantiates Queue<int>::assign(vector<int>::iterator,
    //                                 vector<int>::iterator)
    qi.assign(vi.begin(), vi.end());
    cout << qi << endl;

    list<SmallInt> li; // give |li| some values
    li.assign(vi.begin(), vi.end());
    qi.assign(li.begin(), li.end());
    cout << qi << endl;

}

