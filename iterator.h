#ifndef ITERATOR_H
#define ITERATOR_H

#include "term.h"
#include "struct.h"
#include "list.h"

#include <vector>
#include <iostream>
using std::cout;

template <class T>
class Iterator
{
  friend class Term;

public:
  void first(){};
  void next(){};
  Term *currentItem() const { return _t; };
  bool isDone() const { return true; };

private:
  Iterator(T *t) : _t(t) {}
  T *_t;
};

template <>
class Iterator<Struct>
{
  friend class Struct;

public:
  void first() { _index = 0; }
  void next() { _index++; }
  Term *currentItem() const { return _s->args(_index); }
  bool isDone() const { return _index >= _s->arity(); }

private:
  Iterator(Struct *s) : _index(0), _s(s) {}
  int _index;
  Struct *_s;
};

template <>
class Iterator<List>
{
  friend class List;

public:
  void first() { _tailList = *_l; }
  Term *currentItem() const { return _tailList.head(); }
  bool isDone() const
  {
    try
    {
      _tailList.head();
    }
    catch (string e)
    {
        return true;
    }
    return false;
  }
  void next() { _tailList = *(_tailList.tail()); }

private:
  Iterator(List *l) : _l(l), _tailList(*l) {}
  List *_l, _tailList;
};

#endif