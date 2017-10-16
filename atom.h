#ifndef ATOM_H
#define ATOM_H

#include "term.h"
#include "variable.h"
#include <string>
using std::string;

class Atom : public Term
{
  public:
    Atom(string s) : _symbol(s) {}
    string symbol() const { return _symbol; }
    bool match(Term &term) { return symbol() == term.value(); }
    bool match(Variable &variable)
    {
        if (variable.isAssignable())
        {
            variable.setValue(this);
            return true;
        }
        else
        {
            return symbol() == variable.value();
        }
    }

  private:
    const string _symbol;
};

#endif