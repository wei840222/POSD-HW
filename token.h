#ifndef TOKEN_H
#define TOKEN_H

#include <string>
using std::string;

class Token
{
  public:
    static const int EOS;
    static const int NONE;
    static const int ATOM;
    static const int ATOMSC;
    static const int NUMBER;
    static const int VAR;

    Token(int type = NONE, string value = "") : _tokenType(type), _tokenValue(value) {}
    int type() { return _tokenType; }
    string value() { return _tokenValue; }
    double valueToDouble() { return stod(_tokenValue); }

  private:
    int _tokenType;
    string _tokenValue;
};

const int Token::EOS = -1;
const int Token::NONE = 0;
const int Token::ATOM = 1;
const int Token::ATOMSC = 2;
const int Token::NUMBER = 3;
const int Token::VAR = 4;

#endif