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

#include <vector>
using std:: vector;
#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;

// implement strcmp-like generic compare function 
// returns 0 if the values are equal, 1 if v1 is larger, -1 if v1 is smaller
template <typename T>
int compare(const T &v1, const T &v2)
{
	cout << "compare(const T&, const T&)" << endl;

	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

// compares elements in two sequences
template <class U, class V>
int compare(U beg1, U end1, V beg2)
{
	cout << "compare(U, U, V)" << endl;

	while (beg1 != end1) {
		if (*beg1 < *beg2) return -1;
		if (*beg2 < *beg1) return 1;
		++beg1, ++beg2;
	}
	return 0;  // if we got here the two sequences are equal
}

// plain functions to handle C-style character strings
int compare(char* v1, char* v2)
{
	cout << "compare(char*, char*)" << endl;

	return strcmp(v1, v2);
}

int compare(const char* v1, const char* v2)
{
	cout << "compare(const char*, const char*)" << endl;

	return strcmp(v1, v2);
}

int main()
{
	// calls compare(const T&,const T&) with T bound to int
	compare(1, 0);     

	// calls compare(const T&,const T&) with T bound to string
	string s1 = "hi", s2 = "world";
	compare(s1, s2);

	// calls ordinary function 
	char *cp1 = "world", *cp2 = "hi";
	compare(cp1, cp2); 

	// calls compare(const T&,const T&) with T bound to const char*
	const char *ccp1 = "world", *ccp2 = "hi";
	compare(ccp1, ccp2); 

	// calls compare(U, U, V)
	vector<int> ivec1(10), ivec2(20);
	compare(ivec1.begin(), ivec1.end(), ivec2.begin());
	
	int ia1[] = {0,1,2,3,4,5,6,7,8,9};
	int ia2[] = {9,8,7,6,5,4,3,2,1,0};

	// calls compare(U, U, V)
	compare(ia1, ia1 + 9, ia2);
	return 0;
}
