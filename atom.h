#ifndef ATOM_H
#define ATOM_H

#include "data.h"
#include <string>
using std::string;

class Atom: public Data
{
public:
    Atom (string atom):_symbol(atom), _value(atom){}
    const string symbol(){return _symbol;}
    const string value(){return _value;}
    const bool match(Data &data){return _value == data.value();}
private:
    string _symbol;
    string _value;
};

#endif