#ifndef VARIABLE_H
#define VARIABLE_H

#include "dataAccess.h"
#include <string>
using std::string;

class Variable: public DataAccess
{
public:
    Variable(string s):_assignable(true), _symbol(s){}
    const string symbol(){return _symbol;}
    const string value(){return _value;}
    const bool match(DataAccess& dataAccess){return value() == dataAccess.value();}
    
    void setValue(string s){_value = s;}
    bool isAssignable(){return _assignable;}
    void disAssignable(){_assignable = false;}

private:
    bool _assignable;
    string _symbol;
    string _value;
};

#endif