#ifndef VARIABLE_H
#define VARIABLE_H

#include "term.h"
#include <string>
using std::string;

#include <iostream>
using namespace std;

class Variable : public Term
{
  public:
    Variable(string s) : _symbol(s), _value(NULL) {}
    string symbol() const { return _symbol; }
    string value() const { return _value->value(); }
    bool match(Term &term)
    {
        if (&term == this)
        {
            return true;
        }
        else if (_value)
        {
            return _value->match(term);
        }
        else
        {
            _value = &term;
            return true;
        }
    }

  private:
    const string _symbol;
    Term *_value;
};

#endif