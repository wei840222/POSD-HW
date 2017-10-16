#ifndef NUMBER_H
#define NUMBER_H

#include "term.h"
#include "variable.h"
#include <string>
using std::string;

class Number: public Term
{
public:
    Number(int i):Term(std::to_string(i)){}
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