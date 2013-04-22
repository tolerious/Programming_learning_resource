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

#include <string>
#include <iostream>

class Screen {
public:
    // interface member functions
    typedef std::string::size_type index;
    char get() const { return contents[cursor]; }
    inline char get(index ht, index wd) const;
    Screen(index ht = 0, index wd = 0): 
       contents(ht * wd, ' '), cursor(0), height(ht), width(wd) { }
    Screen& move(index r, index c);
    Screen& set(char);
    Screen& set(index, index, char);
    // display overloaded on whether the object is const or not
    Screen& display(std::ostream &os) 
                  { do_display(os); return *this; }
    const Screen& display(std::ostream &os) const
                  { do_display(os); return *this; }
private:
     // single function to do the work of displaying a Screen,
     // will be called by the display operations
     void do_display(std::ostream &os) const
                       { os << contents; }
    // as before
private:
    std::string contents;
    index cursor;
    index height, width;
    // other members as before
};

Screen& Screen::set(char c) 
{ 
    contents[cursor] = c; 
    return *this; 
}

Screen& Screen::move(index r, index c)
{
    index row = r * width; // row location
    cursor = row + c;
    return *this;
}

Screen& Screen::set(index r, index c, char ch)
{
    index row = r * width; // row location
    contents[row + c] = ch;
    return *this;
}

char Screen::get(index r, index c) const
{
    index row = r * width; // row location
    return contents[row + c];
}

