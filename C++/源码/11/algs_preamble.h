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

// following include and using only to inject abort into the list of names
// for the name to header mapping in the appendix
#include <cstdlib>
using std::abort;
#include <cstddef>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iterator>

using std::vector; using std::list; using std::map; using std::set;  
using std::pair; using std::string; 
using std::istream; using std::ostream; using std::ifstream; 
using std::ofstream; using std::fstream;
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::istream_iterator; using std::ostream_iterator;
using std::find;  using std::sort; using std::stable_sort; using std::for_each;
using std::count; using std::count_if; using std::copy; using std::unique;
using std::unique_copy; using std::back_inserter; using std::reverse_iterator;
using std::inserter; using std::front_inserter;
using std::inner_product; using std::getline; using std::equal_range;
using std::fill; using std::fill_n; using std::accumulate;
using std::partial_sort; using std::nth_element; using std::find_first_of;
using std::replace; using std::replace_copy; using std::set_intersection;

ifstream& open_file(ifstream&, const string&);
// copy constructor used to copy the return value; 
// parameters are references, so they aren't copied
string make_plural(size_t, const string&, const string&);

