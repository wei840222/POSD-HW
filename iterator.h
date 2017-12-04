#ifndef ITERATOR_H
#define ITERATOR_H

#include "term.h"
#include "atom.h"
#include "number.h"
#include "variable.h"
#include "struct.h"
#include "list.h"

#include <vector>
#include <iostream>
using std::cout;

template <class T>
class Iterator
{
  public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual Term *currentItem() const = 0;
    virtual bool isDone() const = 0;
};

template <class T>
class NullIterator : public Iterator<T>
{
  public:
    NullIterator(Term *term) : _term(term) {}
    void first() {}
    void next() {}
    Term *currentItem() const { return _term; }
    bool isDone() const { return true; }

  private:
    Term *_term;
};

template <class T>
class StructIterator : public Iterator<T>
{
  public:
    friend class Struct;
    void first() { _index = 0; }
    Term *currentItem() const { return _s->args(_index); }
    bool isDone() const { return _index >= _s->arity(); }
    void next() { _index++; }

  private:
    StructIterator(Struct *s) : _index(0), _s(s) {}
    int _index;
    Struct *_s;
};

template <class T>
class ListIterator : public Iterator<T>
{
  public:
    friend class List;
    void first() { _index = 0; }
    Term *currentItem() const { return _l[_index]; }
    bool isDone() const { return _index >= _l.size(); }
    void next() { _index++; }

  private:
    ListIterator(List *l) : _index(0)
    {
        List visList = *l;
        while (visList.tail()->symbol() != "[]")
        {
            _l.push_back(visList.head());
            visList = *(visList.tail());
        }
        _l.push_back(visList.head());
    }
    int _index;
    vector<Term *> _l;
};

template <class T>
class DFSIterator : public Iterator<T>
{
  public:
    friend class Struct;
    friend class List;

    void first()
    {
        _stack.clear();
        _stack.push_back(term->createIterator());
    }

    Term *currentItem() const { return _stack.back()->currentItem() }

    bool isDone() const
    {
        if (_stack.size() == 0)
            return true;
        else
            return false;
    }

    void next()
    {
    }

  private:
    DFSIterator(T term) : _term(term) { _stack.push_back(term->createIterator()); }
    T _term;
    vector<Iterator<Term *> *> _stack;
};

#endif