#ifndef PARSER_H
#define PARSER_H

#include <string>
using std::string;

#include "atom.h"
#include "number.h"
#include "variable.h"
#include "struct.h"
#include "list.h"
#include "scanner.h"

class Parser
{
public:
  Parser(Scanner scanner) : _scanner(scanner) {}
  Term *createTerm()
  {
    int token = _scanner.nextToken();
    if (token == VAR)
    {
      return new Variable(symtable[_scanner.tokenValue()].first);
    }
    else if (token == NUMBER)
    {
      return new Number(_scanner.tokenValue());
    }
    else if (token == ATOM)
    {
      Atom *atom = new Atom(symtable[_scanner.tokenValue()].first);
      if (_scanner.nextToken() == '(')
      {
        vector<Term *> terms = getArgs();
        if (_currentToken == ')')
          return new Struct(*atom, terms);
      }
      else
        return atom;
    }
    return NULL;
  }

  vector<Term *> getArgs()
  {
    Term *term = createTerm();
    vector<Term *> args;
    if (term)
      args.push_back(term);
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
