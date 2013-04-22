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

// determine whether a given word is greater than length 6
// will reimplement later as a more general version using function objects
bool GT6(const string &s)
{
	return s.size() >= 6;
}

inline double
percent(double numerator, double denominator)
{
	return 100 * numerator/denominator;
}

// report number of words greater than 6
// later chapter will reimplement to be more general
void report_complexity(vector<string>::iterator beg,
                       vector<string>::iterator end,
                       ostream &output = cout)
{

	vector<string>::difference_type cnt = 
	                         count_if(beg, end, GT6);

	output << "Number of unique words in the input " 
	       << end - beg << endl;
	output << cnt << " "
	       <<  make_plural(cnt, "word", "s")
	       << " 6 characters or longer" << endl;
	output << "Percentage of words 6 characters or more " 
	       << percent(cnt, end - beg) << endl;
}

ifstream &open_file(ifstream&, const string&);

ifstream &prompt_user(ifstream &stream)
{
    // loops until we get a valid stream or the user asks to quit
    while (true) {
        // ask for name of the file to open
        string filename;
        cout << "Please enter file name."
             << "Hit Enter to quit: \n";
        getline(cin, filename);  // read the filename
        // terminate the loop on either empty line or eof
        if (!cin || filename == "") {
            // set condition state to indicate failure & eof
            stream.setstate(
                 ifstream::eofbit | ifstream::failbit);
            return stream;
        }

        // use getline in case user enters a filename with spaces
        if (open_file(stream, filename)) return stream;

        // otherwise, stream wasn't valid, prompt user to try again
        cerr << "oops! unable to open file"
             << filename
             << " please try again!" << endl;
    }
}

// calls open_file to ask the user for the next book to process
// builds a vector<book> that contains the contents of each book 
vector<string> get_books()
{
	ifstream infile;    // stream bound to the next book file
	vector<string> ret; // data structure we'll return to our caller

	// prompt_user asks user for next book and binds infile to it
	while (prompt_user(infile)) {

		// iterator to read the text of the book
		istream_iterator<string> in_iter(infile), eos;

		// read contents of the book into this book's vector
		ret.insert(ret.end(), in_iter, eos);

		infile.close();  // close the file when we're done with it
	}
	return ret;
}


int main()
{
	// read the contents of the books to analyze
	vector<string> words = get_books();

	// sort the input so that we can eliminate duplicates
	sort(words.begin(), words.end());

	// unique reorders elements and returns iterator to end of unique range
	// erase uses that iterator to erase non-unique elements
	words.erase(unique(words.begin(), words.end()), 
	            words.end());

	// sort the words by size, but maintain alphabetic order for words of the same size
	stable_sort(words.begin(), words.end(), isShorter);

	// analyze complexity: report frequency of words of each size
	// and total number/% of words greaten than length 6
	report_complexity(words.begin(), words.end());

	return 0;
}
