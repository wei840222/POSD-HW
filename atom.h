#ifndef ATOM_H
#define ATOM_H

#include "term.h"
#include "variable.h"
#include <string>
using std::string;

class Atom: public Term
{
public:
    Atom (string s):_symbol(s){}
    string symbol(){return _symbol;}
    string value(){return _symbol;}
    bool match(Term& term){return value() == term.value();}
    bool match(Variable& variable)
    {
        if(variable.isAssignable())
        {
            variable.setValue(value());
            variable.disAssignable();
            return true;
        }
        else
        {
            return value() == variable.value();
        }
    }
    
private:
    const string _symbol;
};

#endif