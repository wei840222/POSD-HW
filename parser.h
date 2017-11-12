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
    else if (_scanner.currentToken()->type() == Token::ATOM)
    {
      return new Atom(_scanner.currentToken()->value());
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
    if (term != nullptr)
    {
      terms->push_back(term);
      while (_scanner.nextToken()->value() == ",")
      {
        terms->push_back(createTerm());
      }
    }
    return terms;
  }

private:
  Scanner _scanner;
};

#endif