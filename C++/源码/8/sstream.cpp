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

void f2()
{

    ostringstream format_message;
    format_message << "val1: " << 512 << "\n"
                   << "val2: " << 1024 << "\n";
    istringstream input_istring(format_message.str());
    int val1 = 0;
    int val2 = 0;
    input_istring >> val1 >> val2;
    input_istring.clear();
    string dump;
    input_istring >> dump >> val1 >> dump >> val2;
    cout << val1 <<  " " << val2 << endl;
}

int main()
{
     int val1 = 512, val2 = 1024;
     ostringstream format_message;

     //  ok: converts values to a string representation
     format_message << "val1: " << val1 << "\n"
                    << "val2: " << val2 << "\n";
    cout << format_message.str() << endl;

{
    // str member obtains the string associated with a stringstream
    istringstream input_istring(format_message.str());

    string dump;  // place to dump the labels from the formatted message

    // extracts the stored ascii values, converting back to arithmetic types
    input_istring >> dump >> val1 >> dump >> val2;

    cout << val1 << " " << val2 << endl; // prints 512 1024
}

    f2();  // call f2, which prints val1 and val2 again

{
    istringstream input_istring;   // empty istringstream
    // bind input_istring to string held in format_message
    input_istring.str(format_message.str());  
}
    return 0;
}

// Sample code to use getline and istringstream to read a line of text
// and then process the line a word at at time
void f3()
{
    string line, word;    // will hold a line and word from input, respectively

    while (getline(cin, line)) {    // read a line from the input into line
        // do per-line processing
        istringstream stream(line); // bind to stream to the line we read
        while (stream >> word) {    // read a word from line 
            // do per-word processing
        }
    }
}
