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

// class that has a pointer member that behaves like a plain pointer
class HasPtr {
public:
    friend ostream& operator<<(ostream&, const HasPtr&);
    // copy of the values we're given
    HasPtr(int *p, int i): ptr(p), val(i) { }

    // const members to return the value of the indicated data member
    int *get_ptr() const { return ptr; }     
    int get_int() const { return val; }

    // nonconst members to change the indicated data member
    void set_ptr(int *p) { ptr = p; }
    void set_int(int i) { val = i; }

    // return or change the value pointed to, so ok for const objects
    int get_ptr_val() const { return *ptr; } 
    void set_ptr_val(int val) const { *ptr = val; }

private:
    int *ptr;
    int val;
};

void show_copy_control()
{
    int i = 42;
    HasPtr p1(&i, 42);
    HasPtr p2 = p1;
    cout << p2.get_ptr_val() << endl;

    p1.set_ptr_val(0);
    cout << p2.get_ptr_val() << endl;
}

int main()
{
    show_copy_control();

    int obj = 0;

    HasPtr ptr1(&obj, 42);  // int* member points to obj, val is 42
    HasPtr ptr2(ptr1);      // int* member points to obj, val is 42

    cout << "(1) ptr1: " << ptr1 << endl << "ptr2: " << ptr2 << endl;

    ptr1.set_ptr_val(42); // sets object to which both ptr1 and ptr2 point
    ptr2.get_ptr_val();   // returns 42
    cout << "(2) ptr1: " << ptr1 << endl << "ptr2: " << ptr2 << endl;

    ptr1.set_int(0);   // changes val member only in ptr1
    ptr2.get_int();    // returns 42
    ptr1.get_int();    // returns 0

    cout << "(3) ptr1: " << ptr1 << endl << "ptr2: " << ptr2 << endl;

    int *ip = new int(42); // dynamically allocated int initialized to 42
    HasPtr ptr(ip, 10);    // HasPtr points to same object as ip does
    delete ip;             // object pointed to by ip is freed
    ptr.set_ptr_val(0); // disaster: The object to which HasPtr points was freed!

    // this statement or the previous one are likely to crash -- 
    // the object to which ptr points was deleted
    cout << "(4) ptr: " << ptr << endl; 

    return 0;
}

ostream& operator<<(ostream &os, const HasPtr &hp)
{
    cout << "*ptr: " << hp.get_ptr_val() << "\tval: " << hp.get_int() << endl;
    return os;
}

