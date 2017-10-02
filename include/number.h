#ifndef NUMBER_H
#define NUMBER_H

#include <string>
using std::string;

class Number
{
public:
    Number(int i): _value(i){}
    string getValue(){return std::to_string(_value);}
private:
    int _value;
};

#endif