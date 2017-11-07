#ifndef PARSER_H
#define PARSER_H

#include "atom.h"
#include "number.h"
#include "variable.h"
#include "struct.h"
#include "list.h"
#include "scanner.h"
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
    int token = _scanner.nextToken();
    _currentToken = token;
    if (token == VAR)
    {
      return new Variable(symtable[_scanner.tokenValue()].first);
    }
    else if (token == NUMBER)
    {
      return new Number(_scanner.tokenValue());
    }
    else if (token == ATOM || token == ATOMSC)
    {
      Atom *atom = new Atom(symtable[_scanner.tokenValue()].first);
      if (_scanner.currentChar() == '(')
      {
        _scanner.nextToken();
        vector<Term *> terms = getArgs();
        if (_currentToken == ')')
          return new Struct(*atom, terms);
      }
      else
        return atom;
    }
    else if (token == '[')
    {
      vector<Term*> terms = getArgs();
      if(_currentToken == ')') throw(std::string("unexpected token"));
      if (_currentToken == ']' || _currentToken == 0)
      {
        return new List(terms);
      }
    }
    return nullptr;
  }

  vector<Term *> getArgs()
  {
    Term *term = createTerm();
    vector<Term *> args = {};
    if (term)
    {
      args.push_back(term);
    }
    if ((_currentToken == ']' || _currentToken == ')') && term == nullptr)
    {
      return args;
    }
    while ((_currentToken = _scanner.nextToken()) == ',')
    {
      args.push_back(createTerm());
    }
    return args;
  } 

private:
  Scanner _scanner;
  int _currentToken;
};
#endif
