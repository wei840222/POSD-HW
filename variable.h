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
    string value() const
    {
        if (!_value)
        {
            return symbol();
        }
        return _value->value();
    }
    bool match(Term &term)
    {
        if (&term == this)
        {
            return true;
        }
        else if (!_value)
        {
            _value = &term;
            return true;
        }
        else
        {
            return _value->match(term);
        }
    }

    bool isAssignable() { return !_value; }
    void setValue(Term *term) { _value = term; }

  private:
    const string _symbol;
    Term *_value;
};

#endif