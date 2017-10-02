#ifndef NUMBER_H
#define NUMBER_H

#include "atom.h"
#include <string>
using std::string;

class Number
{
public:
    Number (string number):_symbol(number), _value(number){}
    string symbol(){return _symbol;}
    string value(){return _value;}
    bool match(Number number){return _value == number.value();}
private:
    string _symbol;
    string _value;
};

#endif