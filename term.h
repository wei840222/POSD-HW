#ifndef TERM_H
#define TERM_H

#include <string>
using std::string;

class Term
{
public:
    Term(string s):_symbol(s){}
    Term(string s, string v):_symbol(s), _value(v){}
    string symbol(){return _symbol;}
    string value(){return _value;}
    virtual bool match(Term& term){return symbol() == term.symbol();}

protected:
    string _symbol;
    string _value;
};

#endif