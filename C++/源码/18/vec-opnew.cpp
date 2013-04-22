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
using std::cout; using std::endl;
#include <memory>

// pseudo-implementation of memory allocation strategy for a vector-like class
template <class T> class Vector {
public:
    Vector(): elements(0), first_free(0), end(0) { }
    void push_back(const T&);
    // . . .
    T& operator[](size_t n) { return elements[n]; }
    const T& operator[](size_t n) const { return elements[n]; }
private:
    static std::allocator<T> alloc; // object to get raw memory
    void reallocate(); // get more space and copy existing elements
    T* elements;       // pointer to first element in the array
    T* first_free;     // pointer to first free element in the array
    T* end;            // pointer to one past the end of the array
    // . . .
};

#include <algorithm>
using std::allocator;
template <class T> allocator<T> Vector<T>::alloc;

using std::max;
using std::uninitialized_copy;
template <class T>
void Vector<T>::reallocate()
{
    // compute size of current array and allocate space for twice as many elements
    std::ptrdiff_t size = first_free - elements; 
    std::ptrdiff_t newcapacity = 2 * max(size, 1);
    T* newelements = alloc.allocate(newcapacity);
 
    // construct copies of the existing elements in the new space
    uninitialized_copy(elements, first_free, newelements);

    // destroy the old elements in reverse order
    for (T *p = first_free; p != elements; /*empty*/ )
        alloc.destroy(--p);
    
    // deallocate the memory that they occupied
    // deallocate cannot be called on a 0 pointer
    if (elements)
        alloc.deallocate(elements, end - elements);
    // make our data structure point to the new elements
    elements = newelements;
    first_free = elements + size;
    end = elements + newcapacity;
}

template <class T>
void Vector<T>::push_back(const T& t)
{
    // are we out of space?
    if (first_free == end)
      reallocate(); // gets more space and copies existing elements to it
    alloc.construct(first_free, t);
    ++first_free;
}

int main()
{
    Vector<int> vi;

    for (int i = 0; i != 10; ++i) {
      vi.push_back(i);
      cout << vi[i] << endl;
    }

    for (int i = 0; i != 10; ++i)
      cout << vi[i] << endl;

    return 0;
}
