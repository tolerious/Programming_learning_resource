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

#include "Basket.h"
#include <algorithm>
using std::multiset; using std::map; using std::pair; using std::size_t;
using std::string; using std::ostream; using std::endl; using std::min;
using std::cout;

// debugging routine to check contents in a Basket
void Basket::display(ostream &os) const
{
    os << "Basket size: " << items.size() << endl;

    // print each distinct isbn in the Basket along with
    // count of how many copies are ordered and what their price will be
    // upper_bound returns an iterator to the next item in the set
    for (const_iter next_item = items.begin();
                    next_item != items.end();
                    next_item = items.upper_bound(*next_item))
    {
        // we know there's at least one element with this key in the Basket
        os << (*next_item)->book() << " occurs " 
           << items.count(*next_item) << " times" 
           << " for a price of " 
           << (*next_item)->net_price(items.count(*next_item)) 
           << endl;
    }
}

void print_total(ostream &, const Item_base&, size_t);

// calculate and print price for given number of copies, applying any discounts 
void print_total(ostream &os, 
                 const Item_base &item, size_t n)
{
    os << "ISBN: " << item.book() // calls Item_base::book
       << "\tnumber sold: " << n << "\ttotal price: "
       // virtual call: which version of net_price to call is resolved at runtime
       << item.net_price(n) 
       << endl;
}

double Basket::total() const
{
    double sum = 0.0;    // holds the running total 

    for (const_iter iter = items.begin(); 
                    iter != items.end();
                    iter = items.upper_bound(*iter)) 
    {
        // we know there's at least one element with this key in the Basket
        print_total(cout, *(iter->h), items.count(*iter));
        // virtual call to net_price applies appropriate discounts, if any
        sum += (*iter)->net_price(items.count(*iter));
    }
    return sum;
}

// if specified number of items are purchased, use discounted price 
double Bulk_item::net_price(size_t cnt) const
{
    if (cnt > min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

// use discounted price for up to a specified number of items
// additional items priced at normal, undiscounted price
double Lim_item::net_price(size_t cnt) const
{
    size_t discounted = min(cnt, max_qty);
    size_t undiscounted = cnt - discounted;
    return discounted * (1 - discount) * price 
           + undiscounted * price;
}

