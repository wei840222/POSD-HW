#ifndef NODE_H
#define NODE_H

#include "term.h"

enum Operators
{
  SEMICOLON,  //; or
  COMMA,      //, and
  EQUALITY,   //= match
  TERM
};

class Node
{
public:
  Node(Operators op, Term *t = 0, Node *l = 0, Node *r = 0) : payload(op), term(t), left(l), right(r) {}

  bool evaluate()
  {
    switch(payload)
    {
      case EQUALITY:
        return left->term->match(*(right->term));
        break;
    }
  }

  Operators payload;
  Term *term;
  Node *left, *right;
};

#endif