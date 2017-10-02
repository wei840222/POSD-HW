#ifndef NUMBER_H
#define NUMBER_H

#include <string>
using std::string;

class Number
{
public:
    Number (string s, string v):_symbol(s), _value(v){}
    string symbol(){return _symbol;}
    string value(){return _value;}
    bool match(Number number){return _value == number.value();}
private:
    string _symbol;
    string _value;
};

#endif