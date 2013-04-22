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

#ifndef QUEUE_H
#define QUEUE_H

//NB: if change the interface in this file, also update Queue_interface.h!!!!
//    and int-Queue.h

#include <iostream>
#include <list>

// declaration that Queue is a template needed for friend declaration in QueueItem
template <class Type> class Queue;
// function template declaration must precede friend declaration in QueueItem
template <class T> 
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class Type> class Queue {
    friend std::ostream& 
    operator<< <Type> (std::ostream&, const Queue<Type>&);
public:
    Queue() { }
public:
    // construct a Queue from a pair of iterators on some sequence
    template <class It> Queue(It beg, It end): items(beg, end) { }

    // replace current Queue by contents delimited by a pair of iterators
    template <class Iter> void assign(Iter beg, Iter end)
                             { items.assign(beg, end); }

    // return element from head of Queue
    // unchecked operation: front on an empty Queue is undefined
    Type& front()             { return items.front(); }
    const Type &front() const { return items.front(); }

    // add element to back of Queue
    void push(const Type &t) { items.push_back(t); }
    // remove element from head of Queue
    void pop()               { items.erase(items.begin()); }

    // true if no elements in the Queue
    bool empty() const       { return items.empty(); }
private:
    std::list<Type> items;
};

template <class Type>
std::ostream& operator<<(std::ostream &os, const Queue<Type> &q)
{
    os << "< ";
    typename std::list<Type>::const_iterator beg = q.items.begin();
    while (beg != q.items.end()) {
        os << *beg << " ";
        ++beg;
    }
    os <<">";
    return os;
}

#endif

