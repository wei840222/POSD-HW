#ifndef ATOM_H
#define ATOM_H

#include "term.h"
#include "variable.h"
#include <string>
using std::string;

class Atom: public Term
{
public:
    Atom(string s):Term(s){}
    bool match(Term& term){return symbol() == term.symbol();}
    bool match(Variable& variable)
    {
        if(variable.isAssignable())
        {
            variable.setValue(symbol());
            variable.disAssignable();
            return true;
        }
        else
        {
            return symbol() == variable.value();
        }
    }
};

#endif