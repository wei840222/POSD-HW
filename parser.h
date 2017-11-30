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

#include <vector>
#include <string>
using std::string;

class Parser
{
public:
  Parser(Scanner scanner) : _scanner(scanner), _scopeStartIndex(0) {}

  Term *createTerm()
  {
    int token = _scanner.nextToken();
    _currentToken = token;
    if (token == VAR)
      return new Variable(symtable[_scanner.tokenValue()].first);
    else if (token == NUMBER)
      return new Number(_scanner.tokenValue());
    else if (token == ATOM || token == ATOMSC)
    {
      Atom *atom = new Atom(symtable[_scanner.tokenValue()].first);
      if (_scanner.currentChar() == '(')
        return structure();
      else
        return atom;
    }
    else if (token == '[')
      return list();
    else
      return nullptr;
  }

  void matchings()
  {
    Term *term = createTerm();
    if (term != nullptr)
    {
      _terms.push_back(term);
      while ((_currentToken = _scanner.nextToken()) == '=' || _currentToken == ',' || _currentToken == ';')
      {
        if (_currentToken == '=')
        {
          Node *l = new Node(TERM, _terms.back());
          _terms.push_back(createTerm());
          Node *r = new Node(TERM, _terms.back());
          _expressionTree = new Node(EQUALITY, 0, l, r);
        }
        else if (_currentToken == ',')
        {
          Node *l = _expressionTree;
          matchings();
          Node *r = _expressionTree;
          _expressionTree = new Node(COMMA, 0, l, r);
          setAsSameScope();
        }
        else if (_currentToken == ';')
        {
          Node *l = _expressionTree;
          _scopeStartIndex = _terms.size();
          matchings();
          Node *r = _expressionTree;
          _expressionTree = new Node(SEMICOLON, 0, l, r);
        }
      }
    }
    //remove symtable .
    if (symtable.back().first == ".")
      symtable.pop_back();
  }

  vector<Term *> &getTerms() { return _terms; }
  Node *expressionTree() { return _expressionTree; }

private:
  void createTerms()
  {
    Term *term = createTerm();
    if (term != nullptr)
    {
      _terms.push_back(term);
      while ((_currentToken = _scanner.nextToken()) == ',')
        _terms.push_back(createTerm());
    }
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
      throw string("unexpected token");
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
      throw string("unexpected token");
  }

  void setAsSameScope()
  {
    for (int i = _scopeStartIndex; i < _terms.size(); i++)
    {
      Variable *currentVar = dynamic_cast<Variable *>(_terms[i]);
      if (currentVar != nullptr)
        for (int j = _scopeStartIndex; j < _terms.size(); j++)
        {
          Struct *currentStruct = dynamic_cast<Struct *>(_terms[j]);
          List *currentList = dynamic_cast<List *>(_terms[j]);
          if (currentStruct != nullptr && currentStruct->findBySymbol(currentVar->symbol()) != nullptr && currentStruct->findBySymbol(currentVar->symbol()) != currentVar)
          {
            currentVar->match(*(currentStruct->findBySymbol(currentVar->symbol())));
          }
          else if (currentList != nullptr && currentList->findBySymbol(currentVar->symbol()) != nullptr && currentList->findBySymbol(currentVar->symbol()) != currentVar)
          {
            currentVar->match(*(currentList->findBySymbol(currentVar->symbol())));
          }
          else if (currentVar->symbol() == _terms[j]->symbol() && j > i)
            currentVar->match(*(_terms[j]));
        }
    }
  }

  vector<Term *> _terms;
  Scanner _scanner;
  int _currentToken;
  int _scopeStartIndex;
  Node *_expressionTree;

  FRIEND_TEST(ParserTest, createArgs);
  FRIEND_TEST(ParserTest, ListOfTermsEmpty);
  FRIEND_TEST(ParserTest, listofTermsTwoNumber);
  FRIEND_TEST(ParserTest, createTerm_nestedStruct3);
};
#endif
