#ifndef VARIABLE_H
#define VARIABLE_H

#include "term.h"
#include <string>
using std::string;

class Variable : public Term
{
  public:
    Variable(string s) : _symbol(s), _value(NULL) {}
    string symbol() const { return _symbol; }
    string value() const
    {
        if (!_value)
            return symbol();
        else
            return _value->value();
    }

    bool match(Term &term)
    {
        if (term.findBySymbol(symbol()) != nullptr && term.findBySymbol(symbol()) != &term)
            return false;
        else if (&term == this)
            return true;
        else if (!_value)
        {
            _value = &term;
            return true;
        }
        else
        {
            if (term.isAssignable())
                return term.match(*this);
            else
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