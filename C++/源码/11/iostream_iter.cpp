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

#include "Sales_item.h"
#include "algs_preamble.h"
int main()
{
    istream_iterator<int> cin_it(cin);   // reads ints from cin
    istream_iterator<int> end_of_stream; // end iterator value

    // initialize vec from the standard input:
    vector<int> vec(cin_it, end_of_stream);

    sort(vec.begin(), vec.end());

    // writes ints to cout using " " as the delimiter
    ostream_iterator<int> output(cout, " ");  

    // write only the unique elements in vec to the standard output
    unique_copy(vec.begin(), vec.end(), output);
    cout << endl;  // write a newline after the output
    return 0;
}

void read_write() {
    ofstream outfile;
    outfile.open("dictionary");

    // write a sequence of strings to the ofstream named outfile
    // placing each string on a separate line
    ostream_iterator<string> os_string(outfile, "\n");

    istream_iterator<int> input(cin), eof;
    ostream_iterator<int> output(cout);  
    while (input != eof)
        *output++ = *input++;
}
