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

// template <class T>
// class NullIterator : public Iterator<T>
// {
//   public:
//     NullIterator(Term *term) : _term(term) {}
//     void first() {}
//     void next() {}
//     Term *currentItem() const { return _term; }
//     bool isDone() const { return true; }

//   private:
//     Term *_term;
// };

// template <class T>
// class StructIterator : public Iterator<T>
// {
//   public:
//     friend class Struct;
//     void first() { _index = 0; }
//     Term *currentItem() const { return _s->args(_index); }
//     bool isDone() const { return _index >= _s->arity(); }
//     void next() { _index++; }

//   private:
//     StructIterator(Struct *s) : _index(0), _s(s) {}
//     int _index;
//     Struct *_s;
// };

// template <class T>
// class ListIterator : public Iterator<T>
// {
//   public:
//     friend class List;
//     void first() { _index = 0; }
//     Term *currentItem() const { return _l[_index]; }
//     bool isDone() const { return _index >= _l.size(); }
//     void next() { _index++; }

//   private:
//     ListIterator(List *l) : _index(0)
//     {
//         List visList = *l;
//         while (visList.tail()->symbol() != "[]")
//         {
//             _l.push_back(visList.head());
//             visList = *(visList.tail());
//         }
//         _l.push_back(visList.head());
//     }
//     int _index;
//     vector<Term *> _l;
// };

#endif