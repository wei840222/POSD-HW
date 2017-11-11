#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"
#include <string>
using std::string;

class Scanner
{
public:
  Scanner(string in = "") : _buffer(in), _pos(0), _currentToken(nullptr) {}

  Token *nextToken()
  {
    if (skipLeadingWhiteSpace() >= _buffer.length())
    {
      _currentToken = new Token();
    }
    else if (isdigit(currentChar()))
    {
      _currentToken = new Token(Token::NUMBER, extractNumber());
    }
    else if (islower(currentChar()))
    {
      _currentToken = new Token(Token::ATOM, extractAtom());
    }
    else if (isSpecialCh(currentChar()))
    {
      _currentToken = new Token(Token::ATOMSC, extractAtomSC());
    }
    else if (isupper(currentChar()) || currentChar() == '_')
    {
      _currentToken = new Token(Token::VAR, extractVar());
    }
    else
    {
      _currentToken = nullptr;
    }
    return currentToken();
  }

  Token *currentToken() { return _currentToken; }

  int skipLeadingWhiteSpace()
  {
    for (; (_buffer[_pos] == ' ' || _buffer[_pos] == '\t') && _pos < _buffer.length(); ++_pos)
      ;
    return position();
  }

  int position() const { return _pos; }

  char currentChar() { return _buffer[_pos]; }

  string extractNumber()
  {
    int posBegin = position();
    while(isdigit(_buffer[_pos]))
    {
      ++_pos;
    }
    return _buffer.substr(posBegin, _pos - posBegin);
  }

  string extractAtom()
  {
    int posBegin = position();
    for (; isalnum(_buffer[_pos]); ++_pos)
      ;
    return _buffer.substr(posBegin, _pos - posBegin);
  }

  string extractAtomSC()
  {
    int posBegin = position();
    for (; isSpecialCh(_buffer[_pos]); ++_pos)
      ;
    return _buffer.substr(posBegin, _pos - posBegin);
  }

  string extractVar()
  {
    int posBegin = position();
    for (; isalnum(_buffer[_pos]) || _buffer[_pos] == '_'; ++_pos)
      ;
    return _buffer.substr(posBegin, _pos - posBegin);
  }

  char extractChar()
  {
    return _buffer[_pos++];
  }

private:
  string _buffer;
  int _pos;
  Token *_currentToken;

  static bool isSpecialCh(char c)
  {
    return c == '+'
           //|| c == '=' // ... the matching operator
           || c == '-' || c == '*' || c == '/' || c == '<' || c == '>' || c == '.' || c == '&' || c == '\\' || c == '~' || c == '^' || c == '$' || c == '#' || c == '@' || c == '?' || c == ':';
  }
};

#endif