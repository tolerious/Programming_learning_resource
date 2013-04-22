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

#include <cstddef>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::size_t;

#include <bitset>
using std::bitset;
int main() 
{
    bitset<32> bitvec; // 32 bits, all zero
    bool is_set = bitvec.any();      // false, all bits are zero
    bool is_not_set = bitvec.none(); // true, all bits are zero

    cout << "bitvec: " << bitvec << endl;


    size_t sz = bitvec.size();  // returns 32

    size_t bits_set = bitvec.count();  // returns number of bits that are on


    // assign 1 to even numbered bits
    for (int index = 0; index != 32; index += 2)
                bitvec[index] = 1; 

    // equivalent loop using set operation
    for (int index = 0; index != 32; index += 2)
                bitvec.set(index); 


    unsigned i;

    cout << "bitvec: positions turned on:\n\t";
    for (int index = 0; index != 32; ++index)
             if (bitvec[index])
                  cout << index << " ";
    cout << endl;


    // equivalent; turn off first bit
    bitvec.reset(0);
    bitvec[0] = 0;


    bitvec.reset(); // set all the bits to 0.
    bitvec.set();   // set all the bits to 1


    bitvec.flip(0);   // reverses value of first bit
    bitvec[0].flip(); // also reverses the first bit
    bitvec.flip();    // reverses value of all bits

    // leaves bitvec unchanged; yields a copy of bitvec with all the bits reversed
    bitvec = ~bitvec;          


    // bitvec1 is smaller than the initializer
    bitset<16> bitvec1(0xffff);  // bits 0 ... 15 are set to 1

    // bitvec2 same size as initializer
    bitset<32> bitvec2(0xffff);  // bits 0 ... 15 are set to 1; 16 ... 31 are 0

    // on a 32-bit machine, bits 0 to 31 initialized from 0xffff
    bitset<128> bitvec3(0xffff); // bits 32 through 127 initialized to zero
    cout << "bitvec1: " << bitvec1 << endl;
    cout << "bitvec2: " << bitvec2 << endl;
    cout << "bitvec2[0] " << bitvec2[0] << endl;
    cout << "bitvec2[31] " << bitvec2[31] << endl;
    cout << "bitvec3: " << bitvec3 << endl;

    string strval("1100");
    bitset<32> bitvec4(strval);

    cout << "strval: " << strval << endl;
    cout << "bitvec4: " << bitvec4 << endl;


{
    string str("1111111000000011001101");
    bitset<32> bitvec5(str, 5, 4); // 4 bits starting at str[5], 1100
    bitset<32> bitvec6(str, str.size() - 4); // use last 4 characters 

    cout << "str: " << str << endl;
    cout << "bitvec5: " << bitvec5 << endl;

    cout << "str: " << str << endl;
    cout << "bitvec6: " << bitvec6 << endl;
}


{
    unsigned long ulong = bitvec3.to_ulong();
    cout << "ulong = " << ulong << endl;
}

    bitset<32> bitvec7 = bitvec2 & bitvec4;

    cout << "bitvec7: " << bitvec7 << endl;

    bitset<32> bitvec8 = bitvec2 | bitvec4;

    cout << "bitvec8: " << bitvec8 << endl;

    cout << "bitvec2: " << bitvec2 << endl;
    return 0;
}
