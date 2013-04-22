#include "MS_Queue.h"
#include <stdexcept>
using std::out_of_range;
#include <iostream>
using std::ostream; 

template <class Type>
void Queue<Type>::copy_elems(const Queue &orig)
{
    // copy elements from orig into this Queue
    // loop stops when pt == 0, which happens when we reach orig.tail
    for (QueueItem<Type> *pt = orig.head; pt; pt = pt->next)
        push(pt->item);  // copy the element
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

template <class Type> void Queue<Type>::destroy()
{
    while (!empty())
        pop();
}


template <class Type> void Queue<Type>::push(const Type &val)
{
    // allocate a new QueueItem object
    QueueItem<Type> *pt = new QueueItem<Type>(val);

    // put item onto existing queue
    if (empty())
        head = tail = pt;   // the queue now has only one element
    else {
        tail->next = pt;    // add new element to end of the queue
        tail = pt;
    }
}

template <class Type> void Queue<Type>::pop()
{
    // pop is unchecked: Popping off an empty Queue is undefined 
    QueueItem<Type>* p = head;  // keep pointer to head so we can delete it
    head = head->next;          // head now points to next element
    delete p;                   // delete old head element
}

template <class Type>
ostream& operator<<(ostream &os, const Queue<Type> &q)
{
    os << "< ";
    QueueItem<Type> *p;
    for (p = q.head; p; p = p->next)
            os << p->item << " ";
    os <<">";
    return os;
}

