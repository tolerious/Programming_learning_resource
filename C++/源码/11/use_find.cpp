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

int main()
{
    // use find to search an array
    int ia[6] = {27, 210, 12, 47, 109, 83};
    int search_value = 83;

    int *result = find(ia, ia + 6, search_value);

    cout << "The value " << search_value
         << (result == ia + 6
               ? " is not present" : " is present")
         << endl;

    // use find to search a vector
{
    // initialize the vector with some values
    int ia[6] = {27, 210, 12, 47, 109, 83};
    vector<int> vec(ia, ia+6);

    // value we'll look for
    int search_value = 42;

    // call find to see if that value is present
    vector<int>::const_iterator result =
            find(vec.begin(), vec.end(), search_value);

    // report the result
    cout << "The value " << search_value
         << (result == vec.end()
               ? " is not present" : " is present")
         << endl;
}

    // use find to search a list
{
    list<int> lst(ia, ia+6);

    int search_value = 47;

    // call find to look through elements in a list
    list<int>::const_iterator result =
             find(lst.begin(), lst.end(), search_value);

    cout << "The value " << search_value
         << (result == lst.end()
               ? " is not present" : " is present")
         << endl;
}
    return 0;
}

