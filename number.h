#ifndef NUMBER_H
#define NUMBER_H

#include "dataAccess.h"
#include "variable.h"
#include <string>
using std::string;

class Number: public DataAccess
{
public:
    Number (int i):_value(i){}
    const string symbol(){return std::to_string(_value);}
    const string value(){return std::to_string(_value);}
    const bool match(DataAccess& dataAccess){return value() == dataAccess.value();}
    const bool match(Variable& variable)
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
    int _value;
};

#endif