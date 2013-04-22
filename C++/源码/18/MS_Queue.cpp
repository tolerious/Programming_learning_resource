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

#include "MS_Queue.h"
#include <stdexcept>
using std::out_of_range;
#include <iostream>
using std::ostream; 

//web-comment-begin

template <class Type>
void
Queue<Type>::copy_elems(const Queue &orig)
{
    // copy elements from orig into this Queue
    QueueItem *pt = orig.head;
    while (pt) {     // last element has next pointer == 0
        push(pt->item);  // copy the element
        pt = pt->next;   // get the next one from orig
    }
}

template <class Type>
Queue<Type>& Queue<Type>::operator=(const Queue &rhs)
{
    if (this != &rhs) {
        // destroy elements on this Queue
        destroy();
        copy_elems(rhs);    // copy from rhs into left-hand Queue
    }
    return *this;
}

template <class Type>
void
Queue<Type>::destroy()
{
    while (!empty())
        pop();
}


template <class Type>
void Queue<Type>::push(const Type &val)
{
    // allocate a new QueueItem object
    QueueItem *pt = new QueueItem(val);

    // put item onto existing queue
    if (empty())
        head = tail = pt;   // queue has only one element
    else
    {
        tail->next = pt;     // add new element to end of queue
        tail = pt;
    }
}

//begin{pop-defn}
template <class Type>
void Queue<Type>::pop()
{
    // pop is unchecked: popping off an empty Queue is undefined 
    QueueItem* p = head;     // keep pointer to head so can delete it
    head = head->next;       // head now points to next element
    delete p;                // delete old head element
}
//end{pop-defn}

template <class Type>
ostream& operator<<(ostream &os, const Queue<Type> &q)
{
    os << "< ";
    typename Queue<Type>::QueueItem *p;
    for (p = q.head; p; p = p->next)
            os << p->item << " ";
    os <<">";
    return os;
}

