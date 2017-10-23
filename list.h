#ifndef LIST_H
#define LIST_H

#include "term.h"

#include <vector>
using std::vector;

class List : public Term
{
public:
  List(vector<Term *> elements) : _elements(elements) {}
  Term *element(int index) { return _elements[index]; }
  // Term *head() const;
  // List *tail() const;
  string symbol() const
  {
    if(_elements.empty())
    {
      return "[]";
    }
    else
    {
      string ret = "[";
      for (int i = 0; i < _elements.size() - 1; i++)
      {
        ret += _elements[i]->symbol() + ", ";
      }
      ret += _elements[_elements.size() - 1]->symbol() + "]";
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
      for (int i = 0; i < _elements.size(); i++)
      {
        if (!_elements[i]->match(*(p->_elements[i])))
          return false;
      }
      return true;
    }
    return false;
  }

private:
  vector<Term *> _elements;
};

#endif
