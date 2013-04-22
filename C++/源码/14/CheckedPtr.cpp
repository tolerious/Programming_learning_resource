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

#include "CheckedPtr.h"
#include <iostream>
using std::cerr; 
#include <stdexcept>
using std::out_of_range;

int& CheckedPtr::operator*() 
{
    if (curr == end)
        throw out_of_range("dereference past the end");
    return *curr; 
}

const int& CheckedPtr::operator*() const
{
    if (curr == end)
        throw out_of_range("dereference past the end");
     return *curr; 
}


// postfix: increment/decrement object but return unchanged value
CheckedPtr CheckedPtr::operator++(int)
{
    // no check needed here, the call to prefix increment will do the check
    CheckedPtr ret(*this);   // save current value
    ++*this;                 // advance one element, checking the increment
    return ret;              // return saved state
}

CheckedPtr CheckedPtr::operator--(int)
{
    // no check needed here, the call to prefix decrement will do the check
    CheckedPtr ret(*this);  // save current value
    --*this;                // move backward one element and check
    return ret;             // return saved state
}

// prefix: return reference to incremented/decremented object
CheckedPtr& CheckedPtr::operator++()
{
    if (curr == end) 
        throw out_of_range
              ("increment past the end of CheckedPtr");

    ++curr;                // advance current state
    return *this;
}

CheckedPtr& CheckedPtr::operator--()
{
    if (curr == beg) 
        throw out_of_range
          ("decrement past the beginning of CheckedPtr");

    --curr;              // move current state back one element
    return *this;
}

