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
    friend class Term;

    void first(){};
    void next(){};
    Term *currentItem() const { return _t; };
    bool isDone() const { return true; };

  private:
    NullIterator(T *t) : _t(t) {}
    Term *_t;
};

template <class T>
class StructIterator : public Iterator<T>
{
  public:
    friend class Struct;

    void first() { _index = 0; }
    void next() { _index++; }
    Term *currentItem() const { return _s->args(_index); }
    bool isDone() const { return _index >= _s->arity(); }

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
    ListIterator(List *l) : _l(l), _tailList(*l) {}
    List *_l, _tailList;
};

// template <class T>
// class DFSIterator : public Iterator<T>
// {
//   public:
//     friend class Term;
//     friend class Struct;
//     friend class List;

//     void first()
//     {
//         iteratorStack.clear();
//         iteratorStack.push_back(_t->createIterator());
//     }
//     void next()
//     {
//         if (iteratorStack.back().isDone())
//             iteratorStack.pop_back();
//         else
//         {
//             iteratorStack.back().next();
//             iteratorStack.push_back(iteratorStack.back().currentItem()->createIterator());
//         }
//     }
//     Term *currentItem() const { return iteratorStack.back().currentItem(); }
//     bool isDone() const { return iteratorStack.empty(); };

//   private:
//     DFSIterator(T *t) : _t(t) {}
//     vector<Iterator<T>> iteratorStack;
//     T *_t;
// };

#endif