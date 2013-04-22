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

#ifndef QUERY_H
#define QUERY_H
#include "TextQuery.h"
#include <string>
#include <set>
#include <iostream>
#include <fstream>

// private, abstract class acts as a base class for concrete query types
class Query_base {
    friend class Query;  
protected:
    typedef TextQuery::line_no line_no;
    virtual ~Query_base() { }
private:
    // eval returns the |set| of lines that this Query matches
    virtual std::set<line_no> 
        eval(const TextQuery&) const = 0; 
    // display prints the query
    virtual std::ostream& 
        display(std::ostream& = std::cout) const = 0;
};


// handle class to manage the Query_base inheritance hierarchy
class Query {
    // these operators need access to the Query_base* constructor
    friend Query operator~(const Query &);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const std::string&);  // builds a new WordQuery

    // copy control to manage pointers and use counting
    Query(const Query &c): q(c.q), use(c.use) { ++*use; }
    ~Query() { decr_use(); }
    Query& operator=(const Query&);

    // interface functions: will call corresponding Query_base operations
    std::set<TextQuery::line_no> 
      eval(const TextQuery &t) const { return q->eval(t); }
    std::ostream &display(std::ostream &os) const
                            { return q->display(os); }
private:
    Query(Query_base *query): q(query), 
                              use(new std::size_t(1)) { }
    Query_base *q;
    std::size_t *use;
    void decr_use() 
    { if (--*use == 0) { delete q; delete use; } }
};

inline Query& Query::operator=(const Query &rhs)
{
    ++*rhs.use; 
    decr_use(); 
    q = rhs.q; 
    use = rhs.use; 
    return *this; 
}

inline std::ostream& 
operator<<(std::ostream &os, const Query &q)
{
    return q.display(os);
}

class WordQuery: public Query_base {
    friend class Query; // Query uses the WordQuery constructor
    WordQuery(const std::string &s): query_word(s) { }

    // concrete class: WordQuery defines all inherited pure virtual functions
    std::set<line_no> eval(const TextQuery &t) const
                      { return t.run_query(query_word); }
    std::ostream& display (std::ostream &os) const 
                          { return os << query_word; }
    std::string query_word;   // word for which to search 
};

inline
Query::Query(const std::string &s): q(new WordQuery(s)),
                               use(new std::size_t(1)) { }

class NotQuery: public Query_base {
    friend Query operator~(const Query &);
    NotQuery(Query q): query(q) { }

    // concrete class: NotQuery defines all inherited pure virtual functions
    std::set<line_no> eval(const TextQuery&) const;
    std::ostream& display(std::ostream &os) const
          { return os << "~(" << query << ")"; }
    const Query query;
};

class BinaryQuery: public Query_base {
protected:
    BinaryQuery(Query left, Query right, std::string op): 
          lhs(left), rhs(right), oper(op) { }

    // abstract class: BinaryQuery doesn't define eval 
    std::ostream& display(std::ostream &os) const
    { return os << "(" << lhs  << " " << oper << " " 
                       << rhs << ")"; }

    const Query lhs, rhs;   // right- and left-hand operands
    const std::string oper; // name of the operator
};
    
class AndQuery: public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(Query left, Query right): 
                        BinaryQuery(left, right, "&") { }

    // concrete class: AndQuery inherits display and defines remaining pure virtual
    std::set<line_no> eval(const TextQuery&) const;
};

class OrQuery: public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(Query left, Query right): 
                BinaryQuery(left, right, "|") { }

    // concrete class: OrQuery inherits display and defines remaining pure virtual
    std::set<line_no> eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return new AndQuery(lhs, rhs);
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return new OrQuery(lhs, rhs);
}

inline Query operator~(const Query &oper)
{
    return new NotQuery(oper);
}

std::ifstream& open_file(std::ifstream&, const std::string&);
TextQuery build_textfile(const std::string&);
bool get_word(std::string&);
bool get_words(std::string&, std::string&);
void print_results(const std::set<TextQuery::line_no>&, const TextQuery&);

#endif
