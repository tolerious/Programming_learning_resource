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
#include <iostream>
using std::cout; using std::endl;

int main()
{
	Sales_item item1(Item_base("123", 45));
	Sales_item item2(Bulk_item("345", 45, 3, .15));
	Sales_item item3(Bulk_item("678", 55, 5, .25));
	Sales_item item4(Lim_item("abc", 35, 2, .10));
	Sales_item item5(Item_base("def", 35));

	Basket sale;
	sale.add_item(item1);

	cout << "added first item" << endl;

	sale.add_item(item1);
	sale.add_item(item1);
	sale.add_item(item1);
	sale.add_item(item2);
	sale.add_item(item2);
	sale.add_item(item2);
	sale.add_item(item2);
	sale.add_item(item2);
	sale.add_item(item2);
	sale.add_item(item2);
	sale.add_item(item2);
	sale.add_item(item3);
	sale.add_item(item3);
	sale.add_item(item3);
	sale.add_item(item3);
	sale.add_item(item3);
	sale.add_item(item3);
	sale.add_item(item3);
	sale.add_item(item3);
	sale.add_item(item4);
	sale.add_item(item4);
	sale.add_item(item4);
	sale.add_item(item4);
	sale.add_item(item4);
	sale.add_item(item4);
	sale.add_item(item5);
	sale.add_item(item5);

	cout << "added last item" << endl;

	sale.display(cout);
	cout << sale.total() << endl;
{
	// arguments are the isbn, price, minimum quantity and discount
	Bulk_item bulk("0-201-82470-1", 50, 5, .19);
	Basket sale;
	sale.add_item(Bulk_item("0-201-82470-1", 50, 5, .19));
	sale.add_item(Lim_item("0-201-54848-8", 35, 2, .10));
	double total = sale.total();
	cout << "Total Sale: " << total << endl;
}
}
