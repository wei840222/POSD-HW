#ifndef VARIABLE_H
#define VARIABLE_H

#include "data.h"
#include <string>
using std::string;

class Variable: public Data
{
public:
    Variable(string s):_symbol(s){}
    const string symbol(){return _symbol;}
    const string value(){return _value;}
    void setValue(string s){_value = s;}
    bool isAssignable(){return _assignable;}
    void disAssignable(){_assignable = false;}

private:
    string _symbol;
    string _value;
    bool _assignable = true;
};

#endif