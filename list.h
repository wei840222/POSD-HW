#ifndef LIST_H
#define LIST_H

#include "term.h"
#include "variable.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class List : public Term
{
public:
  List() {}
  List(vector<Term *> elements) : _elements(elements) {}

  string symbol() const
  {
    if (_elements.empty())
      return "[]";
    else
    {
      string ret = "[";
      for (int i = 0; i < _elements.size() - 1; i++)
        ret += _elements[i]->symbol() + ", ";
      ret += _elements[_elements.size() - 1]->symbol() + "]";
      return ret;
    }
  }

  string value() const
  {
    if (_elements.empty())
      return "[]";
    else
    {
      string ret = "[";
      for (int i = 0; i < _elements.size() - 1; i++)
        ret += _elements[i]->value() + ", ";
      ret += _elements[_elements.size() - 1]->value() + "]";
      return ret;
    }
  }

  bool match(Term &term)
  {
    List *p = dynamic_cast<List *>(&term);
    if (p)
    {
      if (_elements.size() != p->_elements.size())
        return false;
      else
      {
        for (int i = 0; i < _elements.size(); i++)
          if (!_elements[i]->match(*(p->_elements[i])))
            return false;
        return true;
      }
    }
    else
      return false;
  }

  bool match(Variable &variable)
  {
    if (findBySymbol(variable.symbol()) != nullptr)
      return false;
    else if (variable.isAssignable())
    {
      variable.setValue(this);
      return true;
    }
    else
      return symbol() == variable.value();
  }

  Term *findBySymbol(string symbol)
  {
    for (int i = 0; i < _elements.size(); i++)
      if (_elements[i]->findBySymbol(symbol) != nullptr)
        return _elements[i]->findBySymbol(symbol);
    return nullptr;
  }

  Term *head()
  {
    if (_elements.empty())
      throw string("Accessing head in an empty list");
    else
      return _elements.front();
  }
  List *tail()
  {
    if (_elements.empty())
      throw string("Accessing tail in an empty list");
    else
    {
      vector<Term *> tail;
      for (int i = 1; i < _elements.size(); i++)
        tail.push_back(_elements[i]);
      List *l = new List(tail);
      return l;
    }
  }

private:
  vector<Term *> _elements;
};

#endif
