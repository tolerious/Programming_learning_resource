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

#include "io_preamble.h"

int main()
{
    // open for input and output and pre-position file pointers to end of file
    fstream inOut("copyOut", 
                   fstream::binary | fstream::ate | fstream::in | fstream::out);
    if (!inOut) {
        cerr << "Unable to open file!" << endl;
        return EXIT_FAILURE;
    } 

    // inOut is opened in  ate mode, so it starts out positioned at the end,
    // which we must remember as it is the original end-of-file position
    ifstream::pos_type end_mark = inOut.tellg();

    inOut.seekg(0, fstream::beg); // reposition to start of the file

    int cnt = 0;                  // accumulator for byte count
    string line;                  // hold each line of input

    // while we haven't hit an error and are still reading the original data 
    // and successfully read another line from the file
    while (inOut.good() && inOut.tellg() != end_mark
                 && getline(inOut, line))
    {
        cnt += line.size() + 1;   // add 1 to account for the newline

	// remember current read marker
	ifstream::pos_type mark = inOut.tellg();  
        inOut.seekp(0, fstream::end);// set write marker to end
        inOut << cnt;             // write the accumulated length
        // print separator if this is not the last line
        if (mark != end_mark) inOut << " "; 
        inOut.seekg(mark);        // restore read position
    }
    inOut.clear();                // clear flags in case we hit an error
    inOut.seekp(0, fstream::end); // seek to end
    inOut << "\n";                // write a newline at end of file

    return 0;
}
