#ifndef NUMBER_H
#define NUMBER_H

#include "data.h"
#include <string>
using std::string;

class Number: public Data
{
public:
    Number (string number):_symbol(number), _value(number){}
    const string symbol(){return _symbol;}
    const string value(){return _value;}
    const bool match(Data &data){return _value == data.value();}

private:
    string _symbol;
    string _value;
};

#endif