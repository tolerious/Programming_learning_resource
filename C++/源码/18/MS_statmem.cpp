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

template <class Type> class Queue {
    // interface functions to Queue are unchanged
public:
    Queue(): head(0), tail(0) { }

    // copy control to manage pointers to QueueItems in the Queue
    Queue(const Queue &Q): head(0), tail(0) {copy_elems(Q);}
    Queue& operator=(const Queue&);
    ~Queue() { destroy(); }

    // return element from head of Queue
    // unchecked operation: front on an empty Queue is undefined
    Type& front()            { return head->item; }
    const Type front() const { return head->item; }

    void push(const Type &);// add element to back of Queue
    void pop();             // remove element from head of Queue

    bool empty() const {    // true if no elements in the Queue
        return head == 0;
    }
private:
    // workaround: MS Compiler doesn't allow nested template class
    // to be defined outside the class body
    //struct QueueItem;  // forward declaration of nested type QueueItem
    struct QueueItem {
        QueueItem(const Type &t): item(t), next(0) { }
        Type item;           // value stored in this element
        QueueItem *next;     // pointer to next element in the Queue
        // MS won't allow definition outside the class so no static members
        // of nested template classes
        //static int static_mem;  
    };

    QueueItem *head;   // pointer to first element in Queue
    QueueItem *tail;   // pointer to last element in Queue

    // utility functions used by copy constructor, assignment and destructor
    void destroy();          // delete all the elements
    void copy_elems(const Queue&); // copy all elements from parameter
private:
    // copy all elements from input range denoted by iterator pair
    // workaround: MS Compiler requires member templates to be 
    // defined inside the class body
    template <class Iter> void copy_elems(Iter, Iter)
    {
        while (beg != end) {
           push(*beg);
           ++beg;
        }
    }
};

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


template <class Type>
void Queue<Type>::pop()
{
    // pop is unchecked: popping off an empty Queue is undefined 
    QueueItem* p = head;     // keep pointer to head so can delete it
    head = head->next;       // head now points to next element
    delete p;                // delete old head element
}

/* workaround: MS Complier doesn't allow member templates to be
 * defined outside the class body
template <class Type> template <class Iter>
void Queue<Type>::copy_elems(Iter beg, Iter end)
{
    while (beg != end) {
       push(*beg);  
       ++beg;
    }
}

* because can't define a member oustide the class, also can't
* have static members of nested template classes
// defines an int static member of QueueItem,
// which is a type nested inside Queue<Type>
template <class Type>
int Queue<Type>::QueueItem::static_mem = 1024;
*/


#include <iostream>
using std::cout; using std::endl;

Queue<int> queue1;

int main() 
{
    for (int ix = 0; ix != 1024; ++ix)
        queue1.push(ix);
    
    for (int ix = 0; ix != 1024; ++ix) {
        int i = queue1.front();  // check next item
        if (i != ix)
             cout << "Something's wrong! i = " << i
                  << " ix = " << ix << endl;
        queue1.pop();   // and remove it
    }

    if (!queue1.empty())
        cout << "Queue is not empty but should be!" << endl;
    else
        cout << "OK, queue empty again" << endl;


    for (int ix = 0; ix != 1024; ++ix)
        queue1.push(ix);

    Queue<int> queue2(queue1);  // use copy constructor

    for (int ix = 0; ix != 1024; ++ix) {
        int i = queue2.front();   // check next item
        if (i != ix)
             cout << "Something's wrong! i = " << i
                  << " ix = " << ix << endl;
        queue2.pop();  // and remove it
    }

    if (!queue2.empty())
        cout << "queue2 is not empty but should be!" << endl;
    else
        cout << "OK, queue2 empty again" << endl;

    queue2 = queue1;  // use asssignment operator
    for (int ix = 0; ix != 1024; ++ix) {
        int i = queue2.front();
        if (i != ix)
             cout << "Something's wrong! i = " << i
                  << " ix = " << ix << endl;
        queue2.pop();
    }

    if (!queue2.empty())
        cout << "queue2 is not empty but should be!" << endl;
    else
        cout << "OK, queue2 empty again" << endl;
    
}
