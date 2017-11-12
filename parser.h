#ifndef PARSER_H
#define PARSER_H

#include "scanner.h"
#include "atom.h"
#include "number.h"
#include "variable.h"
#include "struct.h"
#include "list.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

#include <iostream>
using std::cout;

class Parser
{
public:
  Parser(Scanner scanner) : _scanner(scanner) {}
  Term *createTerm()
  {
    _scanner.nextToken();
    if (_scanner.currentToken()->type() == Token::VAR)
    {
      return new Variable(_scanner.currentToken()->value());
    }
    else if (_scanner.currentToken()->type() == Token::NUMBER)
    {
      return new Number(_scanner.currentToken()->valueToDouble());
    }
    else if (_scanner.currentToken()->type() == Token::ATOM || _scanner.currentToken()->type() == Token::ATOMSC)
    {
      Atom *atom = new Atom(_scanner.currentToken()->value());
      int pos = _scanner.position();
      if (_scanner.nextToken()->value() == "(")
      {
        vector<Term *> *terms = createTerms();
        if (_scanner.currentToken()->value() == ")")
        {
          return new Struct(*atom, *terms);
        }
        else
        {
          throw string("unexpected token");
        }
      }
      else
      {
        _scanner.setPosition(pos);
        return atom;
      }
    }
    else if (_scanner.currentToken()->type() == Token::NONE)
    {
      if (_scanner.currentToken()->value() == "[")
      {
        vector<Term *> *terms = createTerms();
        if (_scanner.currentToken()->value() == "]")
        {
          return new List(*terms);
        }
        else
        {
          throw string("unexpected token");
        }
      }
      else
      {
        return nullptr;
      }
    }
    else
    {
      return nullptr;
    }
  }

  vector<Term *> *createTerms()
  {
    vector<Term *> *terms = new vector<Term *>();
    Term *term = createTerm();
    if (term == nullptr && (_scanner.currentToken()->value() == ")" || _scanner.currentToken()->value() == "]"))
    {
      return terms;
    }
    else
    {
      terms->push_back(term);
      while (_scanner.nextToken()->value() == ",")
      {
        terms->push_back(createTerm());
      }
      return terms;
    }
  }

private:
  Scanner _scanner;
};

#endif