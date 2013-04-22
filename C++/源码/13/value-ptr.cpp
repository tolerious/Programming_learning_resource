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

/*
 * Valuelike behavior even though HasPtr has a pointer member:
 * Each time we copy a HasPtr object, we make a new copy of the
 * underlying int object to which ptr points.
*/
class HasPtr {
public:
    // no point to passing a pointer if we're going to copy it anyway
    // store pointer to a copy of the object we're given
    HasPtr(const int &p, int i): ptr(new int(p)), val(i) {}

    // copy members and increment the use count
    HasPtr(const HasPtr &orig):
       ptr(new int (*orig.ptr)), val(orig.val) { }

    HasPtr& operator=(const HasPtr&);
    // wrong: don't define a destructor without also defining copy and assign
    ~HasPtr() { delete ptr; } 
    friend ostream& operator<<(ostream&, const HasPtr&);

    // accessors must change to fetch value from Ptr object
    int get_ptr_val() const { return *ptr; } 
    int get_int() const { return val; }

    // change the appropriate data member
    void set_ptr(int *p) { ptr = p; }
    void set_int(int i)  { val = i; }

    // return or change the value pointed to, so ok for const objects
    int *get_ptr() const { return ptr; } 
    void set_ptr_val(int p) const { *ptr = p; }
private:
    int *ptr;        // points to an int
    int val;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    // Note: Every HasPtr is guaranteed to point at an actual int;
    //       We know that ptr cannot be a zero pointer
    *ptr = *rhs.ptr;      // copy the value pointed to
    val = rhs.val;        // copy the int 
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

    HasPtr ptr1(obj, 42);  // int* member points copy of obj, val is 42
    HasPtr ptr2(ptr1);     // int* member points new copy obj, val is 42

    cout << "(1) ptr1: " << ptr1 << endl << "ptr2: " << ptr2 << endl;

    ptr1.set_ptr_val(42); // sets copy in ptr1; value in ptr2 unchanged
    ptr2.get_ptr_val();   // returns 0

    cout << "(2) ptr1: " << ptr1 << endl << "ptr2: " << ptr2 << endl;

    ptr1.set_int(0);   // changes val member only in ptr1
    ptr2.get_int();    // returns 42
    ptr1.get_int();    // returns 0

    cout << "(3) ptr1: " << ptr1 << endl << "ptr2: " << ptr2 << endl;

    int *ip = new int(42); // dynamically allocated int initialized to 42
    HasPtr ptr(*ip, 10);    // HasPtr points to same object as ip does
    delete ip;          // object pointed to by ip is freed
    ptr.set_ptr_val(0); // ok: ptr has its own copy

    cout << "(4) ptr: " << ptr << endl;
}
