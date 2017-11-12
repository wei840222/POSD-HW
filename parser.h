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
    else
    {
      return nullptr;
    }
  }

private:
  Scanner _scanner;
};

#endif