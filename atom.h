#ifndef ATOM_H
#define ATOM_H

#include "number.h"
#include <string>
using std::string;

class Atom
{
public:
    Atom (string atom):_symbol(atom), _value(atom){}
    string symbol(){return _symbol;}
    string value(){return _value;}
    bool match(Atom atom){return _value == atom.value();}
    bool match(Number number){return _value == number.value();}
private:
    string _symbol;
    string _value;
};

#endif