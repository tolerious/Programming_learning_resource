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
using std::ostream; using std::cout; using std::endl;
#include <string>
#include <cstddef>
using std::size_t;
/* smart pointer class: takes ownership of the dynamically allocated
 *                      object to which it is bound 
 * User code must dynamically allocate an object to initialize a HasPtr
 * and must not delete that object; the HasPtr class will delete it
*/
//private class for use by HasPtr only
class U_Ptr {
	friend class HasPtr;
	int *ip;
	size_t use;
	U_Ptr(int *p): ip(p), use(1) { }
	~U_Ptr() { delete ip; }
};

class HasPtr {
public:
    // HasPtr owns the pointer; p must have been dynamically allocated
    HasPtr(int *p, int i): ptr(new U_Ptr(p)), val(i) { }

    // copy members and increment the use count
    HasPtr(const HasPtr &orig):
       ptr(orig.ptr), val(orig.val) { ++ptr->use; }
    HasPtr& operator=(const HasPtr&);

    // if use count goes to zero, delete the U_Ptr object
    ~HasPtr() { if (--ptr->use == 0) delete ptr; } 

    friend ostream& operator<<(ostream&, const HasPtr&);
    // copy control and constructors as before

    // accessors must change to fetch value from U_Ptr object
    int *get_ptr() const { return ptr->ip; } 
    int get_int() const { return val; }

    // change the appropriate data member
    void set_ptr(int *p) { ptr->ip = p; }
    void set_int(int i) { val = i; }

    // return or change the value pointed to, so ok for const objects
    // Note: *ptr->ip is equivalent to *(ptr->ip)
    int get_ptr_val() const { return *ptr->ip; } 
    void set_ptr_val(int i) { *ptr->ip = i; }
private:
    U_Ptr *ptr;        // points to use-counted U_Ptr class
    int val;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    ++rhs.ptr->use;     // increment use count on rhs first
    if (--ptr->use == 0)
         delete ptr;    // if use count goes to 0 on this object, delete it
    ptr = rhs.ptr;      // copy the U_Ptr object
    val = rhs.val;      // copy the int member
    return *this;
}

ostream& operator<<(ostream &os, const HasPtr &hp)
{
    os << "*ptr: " << hp.get_ptr_val() << "\tval: " << hp.get_int() << endl;
    return os;
}

int main()
{
    int obj = 0;

    HasPtr ptr1(&obj, 42);
    HasPtr ptr2(ptr1);
    cout << "(1) ptr1: " << ptr1 << endl << "ptr2: " << ptr2 << endl;

    ptr1.set_ptr_val(42); // sets object to which both ptr1 and ptr2 point
    ptr2.get_ptr_val();   // returns 42

    cout << "(2) ptr1: " << ptr1 << endl << "ptr2: " << ptr2 << endl;

    ptr1.set_int(0);   // changes s member only in ptr1
    ptr2.get_int();    // returns 42
    ptr1.get_int();    // returns 0

    cout << "(3) ptr1: " << ptr1 << endl << "ptr2: " << ptr2 << endl;
}

