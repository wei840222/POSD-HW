#ifndef STRUCT_H
#define STRUCT_H

#include "atom.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

class Struct : public Term
{
public:
  Struct(Atom name, vector<Term *> args) : _name(name), _args(args) {}
  Atom name() { return _name; }
  int arity() const { return _args.size(); }
  Term *args(int index) { return _args[index]; }
  string symbol() const
  {
    string ret = _name.symbol() + "(";
    if (arity() == 0)
    {
      ret += ")";
      return ret;
    }
    for (int i = 0; i < _args.size() - 1; i++)
    {
      ret += _args[i]->symbol() + ", ";
    }
    ret += _args[_args.size() - 1]->symbol() + ")";
    return ret;
  }

  string value() const
  {
    string ret = _name.value() + "(";
    if (arity() == 0)
    {
      ret += ")";
      return ret;
    }
    for (int i = 0; i < _args.size() - 1; i++)
    {
      ret += _args[i]->value() + ", ";
    }
    ret += _args[_args.size() - 1]->value() + ")";
    return ret;
  }

  bool match(Term &term)
  {
    Struct *ps = dynamic_cast<Struct *>(&term);
    if (ps)
    {
      if (!_name.match(ps->_name))
        return false;
      if (_args.size() != ps->_args.size())
        return false;
      for (int i = 0; i < _args.size(); i++)
      {
        if (_args[i]->symbol() != ps->_args[i]->symbol())
          return false;
      }
      return true;
    }
    return false;
  }
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
  bool isContain(string symbol)
  {
    for (int i = 0; i < _args.size(); i++)
    {
      if (symbol == _args[i]->symbol() || _args[i]->isContain(symbol))
      {
        return true;
      }
    }
  }

private:
  Atom _name;
  vector<Term *> _args;
};

#endif