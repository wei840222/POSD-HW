#ifndef ATOM_H
#define ATOM_H

#include <string>
using std::string;

class Atom
{
public:
    Atom (string s, string v):_symbol(s), _value(v){}
    string symbol(){return _symbol;}
    string value(){return _value;}
    bool match(Atom atom){return _value == atom.value();}
private:
    string _symbol;
    string _value;
};

#endif