#ifndef TERM_H
#define TERM_H

#include <string>
using std::string;

template <class T>
class Iterator;

class Term
{
public:
  virtual string symbol() const = 0;
  virtual string value() const { return symbol(); }
  virtual void setValue(Term *term) { throw string("unacceptable set value to Term"); }
  virtual bool isAssignable() { return false; }

  virtual bool match(Term &term)
  {
    if (term.isAssignable())
    {
      term.setValue(this);
      return true;
    }
    else
      return symbol() == term.value();
  }

  virtual Term *findBySymbol(string symbol)
  {
    if (symbol == this->symbol())
      return this;
    else
      return nullptr;
  }
  
  virtual Iterator<Term> *createIterator();
};

#endif