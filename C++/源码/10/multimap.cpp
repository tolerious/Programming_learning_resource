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

#include "assoc_preamble.h"

#include "assoc_preamble.h"

int main()
{
    // map from author to title; there can be multiple titles per author
    multimap<string, string> authors;
    // add data to authors
    authors.insert(pair<string, string>("Alain de Botton", "book1"));
    authors.insert(pair<string, string>("Alain de Botton", "book2"));
    authors.insert(pair<string, string>("Alain de Botton", "book3"));
    authors.insert(pair<string, string>("Alain de Botton", "book4"));

    // author we'll look for
    string search_item("Alain de Botton");

    // how many entries are there for this author
    typedef multimap<string, string>::size_type sz_type;
    sz_type entries = authors.count(search_item);

    // get iterator to the first entry for this author
    multimap<string,string>::iterator iter = 
                             authors.find(search_item);

    // loop through the number of entries there are for this author
    for (sz_type cnt = 0; cnt != entries; ++cnt, ++iter)
           cout << iter->second << endl; // print each title

    // definitions of authors and search_item as above

    // beg and end denote range of elements for this author
    typedef multimap<string, string>::iterator authors_it;
    authors_it beg = authors.lower_bound(search_item),
               end = authors.upper_bound(search_item);

    // loop through the number of entries there are for this author
    while (beg != end) {
        cout << beg->second << endl; // print each title
        ++beg;
    }

    // definitions of authors and search_item as above

    // pos holds iterators that denote range of elements for this key
    pair<authors_it, authors_it> 
                     pos = authors.equal_range(search_item);

    // loop through the number of entries there are for this author
    while (pos.first != pos.second) {
        cout << pos.first->second << endl; // print each title
        ++pos.first;
    }
    return 0;
}

