#ifndef NUMBER_H
#define NUMBER_H

#include "term.h"
#include "variable.h"
#include <string>
using std::string;

class Number: public Term
{
public:
    Number (int i):_value(i){}
    string symbol(){return std::to_string(_value);}
    string value(){return std::to_string(_value);}
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
    const int _value;
};

#endif