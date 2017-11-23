#ifndef PARSER_H
#define PARSER_H

#include "term.h"
#include "atom.h"
#include "number.h"
#include "variable.h"
#include "struct.h"
#include "list.h"
#include "scanner.h"
#include "node.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;

class Parser
{
public:
  Parser(Scanner scanner) : _scanner(scanner), _terms() {}

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
        return structure();
      }
      else
        return atom;
    }
    else if (token == '[')
    {
      return list();
    }

    return nullptr;
  }

  Term *structure()
  {
    Atom structName = Atom(symtable[_scanner.tokenValue()].first);
    int startIndexOfStructArgs = _terms.size();
    _scanner.nextToken();
    createTerms();
    if (_currentToken == ')')
    {
      vector<Term *> args(_terms.begin() + startIndexOfStructArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfStructArgs, _terms.end());
      return new Struct(structName, args);
    }
    else
    {
      throw string("unexpected token");
    }
  }

  Term *list()
  {
    int startIndexOfListArgs = _terms.size();
    createTerms();
    if (_currentToken == ']')
    {
      vector<Term *> args(_terms.begin() + startIndexOfListArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfListArgs, _terms.end());
      return new List(args);
    }
    else
    {
      throw string("unexpected token");
    }
  }

  vector<Term *> &getTerms()
  {
    return _terms;
  }

  void matchings()
  {
    _terms.clear();
    _expressionTree = matching();
    while ((_currentToken = _scanner.nextToken()) != EOS)
    {
      switch (_currentToken)
      {
      case ',':
        Node *l = _expressionTree;
        Node *r = matching();
        _expressionTree = new Node(COMMA, 0, r, l);
        break;
      }
    }
  }

  Node *matching()
  {
    int i = _terms.size();
    _terms.push_back(createTerm());
    if ((_currentToken = _scanner.nextToken()) == '=')
    {
      Node *l = new Node(TERM, _terms[i]);
      _terms.push_back(createTerm());
      Node *r = new Node(TERM, _terms[i + 1]);
      return new Node(EQUALITY, 0, l, r);
    }
    else
      throw string("matching is wrong!");
  }

  Node *expressionTree() { return _expressionTree; }

private:
  FRIEND_TEST(ParserTest, createArgs);
  FRIEND_TEST(ParserTest, ListOfTermsEmpty);
  FRIEND_TEST(ParserTest, listofTermsTwoNumber);
  FRIEND_TEST(ParserTest, createTerm_nestedStruct3);

  void createTerms()
  {
    Term *term = createTerm();
    if (term != nullptr)
    {
      _terms.push_back(term);
      while ((_currentToken = _scanner.nextToken()) == ',')
      {
        _terms.push_back(createTerm());
      }
    }
  }

  vector<Term *> _terms;
  Scanner _scanner;
  int _currentToken;
  Node *_expressionTree;
};
#endif
