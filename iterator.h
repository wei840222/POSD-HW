#ifndef ITERATOR_H
#define ITERATOR_H

#include "term.h"
#include "struct.h"
#include "list.h"

#include <vector>
using std::vector;
#include <queue>
using std::queue;

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
    virtual Term *currentTerm() const = 0;
};

template <class T>
class NullIterator : public Iterator<T>
{
  public:
    friend class Term;

    void first(){};
    void next(){};
    Term *currentItem() const { return nullptr; };
    bool isDone() const { return true; };
    Term *currentTerm() const { return _t; };

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
    Term *currentTerm() const { return _s; };

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
    void next()
    {
        try
        {
            _tailList = *(_tailList.tail());
        }
        catch (string e)
        {
        }
    }
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
    Term *currentTerm() const { return _l; };

  private:
    ListIterator(List *l) : _l(l), _tailList(*l) {}
    List *_l, _tailList;
};

template <class T>
class DFSIterator : public Iterator<T>
{
  public:
    friend class Struct;
    friend class List;

    void first()
    {
        _iteratorStack.clear();
        _iteratorStack.push_back(_t->createIterator());
    }
    void next()
    {
        if (!isDone())
        {
            if (currentItem()->createIterator()->isDone())
            {
                _iteratorStack.back()->next();
                if (_iteratorStack.back()->isDone())
                {
                    _iteratorStack.pop_back();
                    if (!isDone())
                        _iteratorStack.back()->next();
                }
            }
            else
                _iteratorStack.push_back(currentItem()->createIterator());
        }
    }
    Term *currentItem() const { return _iteratorStack[_iteratorStack.size() - 1]->currentItem(); }
    bool isDone() const { return _iteratorStack.empty(); };
    Term *currentTerm() const { return _t; };

  private:
    DFSIterator(T *t) : _t(t) { _iteratorStack.push_back(_t->createIterator()); }
    vector<Iterator<Term> *> _iteratorStack;
    T *_t;
};

template <class T>
class BFSIterator : public Iterator<T>
{
  public:
    friend class Struct;
    friend class List;

    void first()
    {
        while (!_iteratorQueue.empty())
            _iteratorQueue.pop();
        _iteratorQueue.push(_t->createIterator());
    }
    void next()
    {
        if (!isDone())
        {
            if (currentItem()->createIterator()->isDone())
            {
                _iteratorQueue.front()->next();
                if (_iteratorQueue.front()->isDone())
                    _iteratorQueue.pop();
            }
            else
            {
                _iteratorQueue.push(currentItem()->createIterator());
                _iteratorQueue.front()->next();
            }
        }
    }
    Term *currentItem() const { return _iteratorQueue.front()->currentItem(); }
    bool isDone() const { return _iteratorQueue.empty(); };
    Term *currentTerm() const { return _t; };

  private:
    BFSIterator(T *t) : _t(t) { _iteratorQueue.push(_t->createIterator()); }
    queue<Iterator<Term> *> _iteratorQueue;
    T *_t;
};

#endif