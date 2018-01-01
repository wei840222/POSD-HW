#ifndef EXP_H
#define EXP_H

#include <string>
#include "term.h"

using std::string;

class Exp
{
public:
  virtual bool evaluate() = 0;
  virtual string getTreeContext() const = 0;
};

class MatchExp : public Exp
{
public:
  MatchExp(Term *left, Term *right) : _left(left), _right(right) {}
  bool evaluate() { return _left->match(*_right); }
  string getTreeContext() const { return _left->symbol() + " = " + _right->symbol(); }

private:
  Term *_left;
  Term *_right;
};

class ConjExp : public Exp
{
public:
  ConjExp(Exp *left, Exp *right) : _left(left), _right(right) {}
  bool evaluate() { return (_left->evaluate() && _right->evaluate()); }
  string getTreeContext() const { return _left->getTreeContext() + "; " + _right->getTreeContext(); }

private:
  Exp *_left;
  Exp *_right;
};

class DisjExp : public Exp
{
public:
  DisjExp(Exp *left, Exp *right) : _left(left), _right(right) {}
  bool evaluate() { return (_left->evaluate() || _right->evaluate()); }
  string getTreeContext() const { return _left->getTreeContext() + ", " + _right->getTreeContext(); }

private:
  Exp *_left;
  Exp *_right;
};

#endif