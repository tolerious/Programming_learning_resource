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

// declaration that Queue is a template needed for friend declaration in QueueItem
template <class Type> class Queue;
// function template declaration must precede friend declaration in QueueItem
template <class T> 
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class Type> class QueueItem {
    friend class Queue<Type>;
    // . . .
    // needs access to item and next
    friend std::ostream& 
    operator<< <Type> (std::ostream&, const Queue<Type>&);
    // . . .

// private class: no public section
    QueueItem(const Type &t): item(t), next(0) { }
    Type item;           // value stored in this element
    QueueItem *next;     // pointer to next element in the Queue
};


template <class Type> class Queue {
    // needs access to head 
    friend std::ostream& 
    operator<< <Type> (std::ostream&, const Queue<Type>&);
public:
    // empty Queue
    Queue(): head(0), tail(0) { }
public:
    // construct a Queue from a pair of iterators on some sequence
    template <class It> 
    Queue(It beg, It end): 
          head(0), tail(0) { copy_elems(beg, end); }
    // . . .

    // copy control to manage pointers to QueueItems in the Queue
    Queue(const Queue &Q): head(0), tail(0) 
                                  { copy_elems(Q); }
    Queue& operator=(const Queue&);
    ~Queue() { destroy(); }

    // replace current Queue by contents delimited by a pair of iterators
    template <class Iter> void assign(Iter, Iter);
    // rest of Queue class as before

    // return element from head of Queue
    // unchecked operation: front on an empty Queue is undefined
    Type& front()             { return head->item; }
    const Type &front() const { return head->item; }

    void push(const Type &);      // add element to back of Queue
    void pop();                   // remove element from head of Queue

    bool empty() const {          // true if no elements in the Queue
        return head == 0;
    }
private:
    QueueItem<Type> *head;         // pointer to first element in Queue
    QueueItem<Type> *tail;         // pointer to last element in Queue

    // utility functions used by copy constructor, assignment, and destructor
    void destroy();                // delete all the elements
    void copy_elems(const Queue&); // copy elements from parameter
private:
    // version of copy to be used by assign to copy elements from iterator range
    template <class Iter> void copy_elems(Iter, Iter); 
};

// Inclusion Compilation Model: include member function definitions as well
#include "Queue.cc"

#endif

