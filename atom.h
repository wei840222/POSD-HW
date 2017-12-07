#ifndef ATOM_H
#define ATOM_H

#include "term.h"
#include "variable.h"
#include <string>
using std::string;

class Atom : public Term
{
public:
  Atom(string s) : Term(s) {}
};

#endif