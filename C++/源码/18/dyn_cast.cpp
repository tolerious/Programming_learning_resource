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

#include <typeinfo>
using std::bad_cast;

#include <iostream>
using std::cout; using std::endl;

void exercises() {
struct A { virtual ~A() { } };
struct B : virtual public A { /* ... */ };
struct C : public B { /* ... */ };
struct D : public B, virtual public A { /* ... */ };

 A *pa = new C;
    if (B *pb = dynamic_cast< B* >(pa))
         cout << "cast from C to B* ok" << endl;
    else
         cout << "cast from C to B* not ok" << endl;
 B *pb = new B;
    if (C *pc = dynamic_cast< C* >(pb))
         cout << "cast from B to C* ok" << endl;
    else
         cout << "cast from B to C* not ok" << endl;

 A *pc = new C;
    if (B *pb = dynamic_cast< B* >(pc))
         cout << "cast C to B* ok" << endl;
    else
         cout << "cast C to B* not ok" << endl;

 A *pd = new D;
    if (B *pb = dynamic_cast< B* >(pd))
         cout << "cast D to B* ok" << endl;
    else
         cout << "cast D to B* not ok" << endl;
}

struct Base {
   virtual void f() {};
   virtual ~Base() {};
};

struct Derived: public Base { };

int main()
{
Base *basePtr; 
basePtr = new Derived;  // basePtr actually points to a Derived object
if (Derived *derivedPtr = dynamic_cast<Derived*>(basePtr)) 
{
    // use the Derived object to which derivedPtr points
} else {  // BasePtr points at a Base object
    // use the Base object to which basePtr points
}
exercises();
}

void f(const Base &b)
{
    try {
        const Derived &d = dynamic_cast<const Derived&>(b);
	// use the Derived object to which b referred
    } catch (bad_cast) {
        // handle the fact that the cast failed
    }
}
