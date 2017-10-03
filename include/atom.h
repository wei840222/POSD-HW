#ifndef ATOM_H
#define ATOM_H

#include "dataAccess.h"
#include <string>
using std::string;

class Atom: public DataAccess
{
public:
    Atom (string s):_symbol(s){}
    const string symbol(){return _symbol;}
    const string value(){return _symbol;}
    const bool match(DataAccess& dataAccess){return value() == dataAccess.value();}
    
private:
    string _symbol;
};

#endif