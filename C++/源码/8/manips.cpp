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
    cout << "default bool values: "
         << true << " " << false
         << "\nalpha bool values: "
         << boolalpha
         << true << " " << false
         << endl;

    bool bool_val = true;
    cout << boolalpha    // sets internal state of cout
         << bool_val
         << noboolalpha; // resets internal state to default formatting
    cout << endl;

    const int ival = 15, jval = 1024;  // const, so values never change

    cout << "default: ival = " << ival 
         << " jval = " << jval << endl;
    cout << "printed in octal: ival = " << oct << ival 
         << " jval = " << jval << endl;

    cout << "printed in hexadecimal: ival = " << hex << ival 
         << " jval = " << jval << endl;

    cout << "printed in decimal: ival = " << dec << ival 
         << " jval = " << jval << endl;

{
    const int ival = 15, jval = 1024;  // const so values never change

    cout << showbase;   // show base when printing integral values

    cout << "default: ival = " << ival 
         << " jval = " << jval << endl;
    cout << "printed in octal: ival = " << oct << ival 
         << " jval = " << jval << endl;
    cout << "printed in hexadecimal: ival = " << hex << ival 
         << " jval = " << jval << endl;
    cout << "printed in decimal: ival = " << dec << ival 
         << " jval = " << jval << endl;

    cout << noshowbase;  // reset state of the stream
}

    cout << uppercase << showbase << hex
         << "printed in hexadecimal: ival = " << ival 
         << " jval = " << jval << endl
         << nouppercase << endl;

    return 0;
}
