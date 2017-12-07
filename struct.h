#ifndef STRUCT_H
#define STRUCT_H

#include "atom.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

template <class T>
class Iterator;
template <class T>
class DFSIterator;
template <class T>
class BFSIterator;

class Struct : public Term
{
public:
  Struct(Atom name, vector<Term *> args) : _name(name), _args(args) {}

  string symbol() const
  {
    string ret = _name.symbol() + "(";
    if (arity() == 0)
    {
      ret += ")";
      return ret;
    }
    else
    {
      for (int i = 0; i < _args.size() - 1; i++)
        ret += _args[i]->symbol() + ", ";
      ret += _args[_args.size() - 1]->symbol() + ")";
      return ret;
    }
  }

  string value() const
  {
    string ret = _name.value() + "(";
    if (arity() == 0)
    {
      ret += ")";
      return ret;
    }
    else
    {
      for (int i = 0; i < _args.size() - 1; i++)
        ret += _args[i]->value() + ", ";
      ret += _args[_args.size() - 1]->value() + ")";
      return ret;
    }
  }

  bool match(Term &term)
  {
    Struct *ps = dynamic_cast<Struct *>(&term);
    if (ps)
    {
      if (!_name.match(ps->_name))
        return false;
      else if (_args.size() != ps->_args.size())
        return false;
      else
      {
        for (int i = 0; i < _args.size(); i++)
          if (_args[i]->symbol() != ps->_args[i]->symbol())
            return false;
        return true;
      }
    }
    else
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

  Term *findBySymbol(string symbol)
  {
    for (int i = 0; i < _args.size(); i++)
      if (_args[i]->findBySymbol(symbol) != nullptr)
        return _args[i]->findBySymbol(symbol);
    return nullptr;
  }

  Atom name() { return _name; }
  int arity() const { return _args.size(); }
  Term *args(int index) { return _args[index]; }

  Iterator<Term *> *createIterator();
  DFSIterator<Term *> *createDFSIterator();
  BFSIterator<Term *> *createBFSIterator();

private:
  Atom _name;
  vector<Term *> _args;
};

#endif