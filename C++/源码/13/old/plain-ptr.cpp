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

void f3()
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

cout << "(4) ptr: " << ptr << endl;

f3();

return 0;
}

void f(int *p) 
{ // new socpe
    // allocates new int to hold a copy of the object to which p points
    HasPtr local_copy(p, 0);
    // . . .
} // local_copy goes out of scope

void f2()
{
    int obj= 42;
    HasPtr local1(&obj, 0); // allocates a new int to hold a copy of obj

    if (obj) { // new scope
        HasPtr local2(local1); // local1 and local2 hold same pointer
        // . . .
    } // local2 goes out of scope, object to which it points is freed
    local1.set_ptr_val(0);  // disaster -- the object to which local1 points was freed!
}

ostream& operator<<(ostream &os, const HasPtr &hp)
{
    cout << "*ptr: " << hp.get_ptr_val() << "\tval: " << hp.get_int() << endl;
    return os;
}

