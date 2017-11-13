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
    Struct *s = dynamic_cast<Struct *>(&term);
    if (s)
    {
      if (!_name.match(s->_name))
      {
        return false;
      }
      else if (_args.size() != s->_args.size())
      {
        return false;
      }
      else
      {
        for (int i = 0; i < _args.size(); i++)
        {
          if (_args[i]->symbol() != s->_args[i]->symbol())
          {
            return false;
          }
        }
        return true;
      }
    }
    else
    {
      return false;
    }
  }
  bool match(Variable &variable)
  {
    if (isContain(&variable))
    {
      return false;
    }
    else if (variable.isAssignable())
    {
      variable.setValue(this);
      return true;
    }
    else
    {
      return symbol() == variable.value();
    }
  }

  bool isContain(Term *term)
  {
    for (int i = 0; i < _args.size(); i++)
    {
      if (term == _args[i])
      {
        return true;
      }
      else if (_args[i]->isContain(term))
      {
        return true;
      }
    }
    return false;
  }

private:
  Atom _name;
  vector<Term *> _args;
};

#endif