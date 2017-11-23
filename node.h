#ifndef NODE_H
#define NODE_H

#include "term.h"

enum Operators
{
  SEMICOLON, //0 ; or
  COMMA,     //1 , and
  EQUALITY,  //2 = match
  TERM       //3
};

class Node
{
public:
  Node(Operators op, Term *t = 0, Node *l = 0, Node *r = 0) : payload(op), term(t), left(l), right(r) {}

  bool evaluate()
  {
    switch (payload)
    {
    case EQUALITY:
      return left->term->match(*(right->term));

    case COMMA:
      return (left->evaluate()) && (right->evaluate());
    }
  }

  Operators payload;
  Term *term;
  Node *left, *right;
};

#endif