#ifndef TERM_H
#define TERM_H

#include <string>
using std::string;

class Term
{
public:
    Term(string s):_symbol(s){}
    virtual string symbol()const{return _symbol;}
    virtual string value()const{return symbol();}
    virtual bool match(Term& term) = 0;

protected:
    const string _symbol;
};

#endif