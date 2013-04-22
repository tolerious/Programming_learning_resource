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

// comparison function to be used to sort by word length
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

// determine whether a length of a given word is longer than a stored bound
class GT_cls {
public:
    GT_cls(size_t val = 0): bound(val) { }
    bool operator()(const string &s) 
                       { return s.size() >= bound; }
private:
    std::string::size_type bound;
};

// determine whether a length of a given word is equal to a stored bound
class EQ {
public:
    EQ(size_t val = 0): bound(val) { }
    bool operator()(const string &s) { return s.size() == bound; }
private:
    size_t bound;
};

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
	vector<string>::iterator last_word =
	            unique(words.begin(), words.end());
	words.erase(last_word, words.end());
	// sort words by size, but maintain alphabetic order for words of the same size
	stable_sort(words.begin(), words.end(), isShorter);
	cout << count_if(words.begin(), words.end(), GT_cls(6)) 
	     << " words 6 characters or longer" << endl;
	cout << count_if(words.begin(), words.end(), GT_cls(5)) 
	     << " words 5 characters or longer" << endl;
	for (size_t i = 0; i != 11; ++i)
	    cout << count_if(words.begin(), words.end(), EQ(i))
	         << " words " << i 
	         << " characters or longer" << endl;
	return 0;  
}
