#include "MS_Queue.h"
// workaround MS compiler bug: doesn't properly handle member specializations
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

// push and pop specialized for const char*
#include"queue_push_char.cpp"


#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	char* hi = "hello";
	Queue<const char*> q1;
	q1.push(hi);
	q1.push("world");
	q1.push("bye");

	cout << q1 << endl;

	for (int i = 0; i != 3; ++i) {
		cout << q1.front() << endl;
		q1.pop();
	}
	
	cout << "q1 is empty? " << ((q1.empty()) ? "yes" : "no") << endl;

	string hi2 = "hello";
	Queue<string> q2;
	q2.push(hi2);
	q2.push("world");
	q2.push("bye");

	cout << q2 << endl;

	for (int i = 0; i != 3; ++i) {
		cout << q2.front() << endl;
		q2.pop();
	}
	
	cout << "q2 is empty? " << ((q2.empty()) ? "yes" : "no") << endl;

	return 0;
}
