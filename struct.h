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
  Term *args(int index) { return _args[index]; }
  string symbol() const
  {
    string ret = _name.symbol() + "(";
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

private:
  Atom _name;
  vector<Term *> _args;
};

#endif