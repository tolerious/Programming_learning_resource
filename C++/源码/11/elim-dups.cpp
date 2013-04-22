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

#include "algs_preamble.h"
#include <fstream>
using std::ifstream;
#include <cstddef>
using std::size_t;

int main()
{
	vector<string> words;
	// copy contents of each book into a single vector
	string next_word;
	while (cin >> next_word) {
		// insert next book's contents at end of words
		words.push_back(next_word);
	}

	// sort words alphabetically so we can find the duplicates
	sort(words.begin(), words.end());

	// print contents to see how things look at this point
	for(vector<string>::iterator it = words.begin(); it != words.end(); ++it)
		cout << *it << " ";
	cout << endl;

	vector<string>::iterator end_unique =
	            unique(words.begin(), words.end());

	// print contents to see how things look at this point
	for(vector<string>::iterator it = words.begin(); it != words.end(); ++it)
		cout << *it << " ";
	cout << endl;

	words.erase(end_unique, words.end());
	
	// print contents to see how things look at this point
	for(vector<string>::iterator it = words.begin(); it != words.end(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;  
}
