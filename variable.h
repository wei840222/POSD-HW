#ifndef VARIABLE_H
#define VARIABLE_H

#include "atom.h"
#include "number.h"
#include <string>
using std::string;

class Variable
{
public:
    Variable(string s):_symbol(s){}
    string symbol(){return _symbol;}
    string value(){return _value;}
    bool match(Atom atom)
    {
        bool status = _assignable;
        if(_assignable)
        {
            _value = atom.value();
            _assignable = false;
        }
        return status;
    }
    bool match(Number number)
    {
        bool status = _assignable;
        if(_assignable)
        {
            _value = number.value();
            _assignable = false;
        }
        return status;
    }

private:
    string _symbol;
    string _value;
    bool _assignable;
};

#endif