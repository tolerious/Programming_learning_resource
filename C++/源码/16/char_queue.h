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

#ifndef QUEUE_CHAR_H
#define QUQUE_CHAR_H

#include "MS_Queue.h"
#include <stdexcept>
#include <iostream>
#include <string>

//NB: if change the Queue interface must also change this file!

template<> class Queue<char*>; // declares specialization for Queue<char*>

template<> class Queue<const char*> {
    friend std::ostream& operator<< 
                      (std::ostream&, const Queue<const char*>&);
public:
    // no copy control: Synthesized  versions work for this class
    // similarly, no need for explicit default constructor either
    void push(const char*);
    void pop()               {real_queue.pop();}
    bool empty() const       {return real_queue.empty();}

    // Note: return type does not match template parameter type
    std::string front()     {return real_queue.front();}
    const std::string &front() const 
                             {return real_queue.front();}
private:
    Queue<std::string> real_queue; // forward calls to real_queue
};

inline
void Queue<const char*>::push(const char* val)
{
    return real_queue.push(val);
}

#endif
