#ifndef TERM_H
#define TERM_H

#include <string>
using std::string;

class Term
{
public:
  virtual string symbol() const = 0;
  virtual string value() const { return symbol(); }
  virtual bool match(Term &term) = 0;
  virtual bool isRecurrsiveMatch(Term *) {return false;}
};

#endif