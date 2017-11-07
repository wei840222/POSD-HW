#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>
#include <algorithm>

using std::pair;
using std::string;
using std::vector;

// no tokenValue
const int NONE = -1;

// tokens return by the scanner
const int EOS = '\0';
const int NUMBER = 256;
const int ATOM = 257;
const int ATOMSC = 258;
const int VAR = 259;

vector<pair<string, int>> symtable;

bool isSpecialCh(char c)
{
  return c == '+'
         //|| c == '=' // ... the matching operator
         || c == '-' || c == '*' || c == '/' || c == '<' || c == '>' || c == '.' || c == '&' || c == '\\' || c == '~' || c == '^' || c == '$' || c == '#' || c == '@' || c == '?' || c == ':';
}

bool symbolExist(string s, int &val)
{
  bool found = false;
  val = -1;
  vector<pair<string, int>>::iterator it = find_if(symtable.begin(), symtable.end(), [s](pair<string, int> ele) {
    return ele.first == s;
  });

  found = symtable.end() != it;
  if (found)
    val = it - symtable.begin();

  return found;
}

class Scanner
{
public:
  Scanner(string in = "") : buffer(in), pos(0), _tokenValue(NONE) {}
  void setInput(string in) { buffer = in; }

  int nextToken()
  {
    if (skipLeadingWhiteSpace() >= buffer.length())
      return EOS;
    else if (isdigit(currentChar()))
    {
      _tokenValue = extractNumber();
      return NUMBER;
    }
    else if (islower(currentChar()))
    {
      string s = extractAtom();
      processToken<ATOM>(s);
      return ATOM;
    }
    else if (isSpecialCh(currentChar()))
    {
      string s = extractAtomSC();
      processToken<ATOMSC>(s);
      return ATOMSC;
    }
    else if (isupper(currentChar()) || currentChar() == '_')
    {
      string s = extractVar();
      processToken<VAR>(s);
      return VAR;
    }
    else
    {
      _tokenValue = NONE;
      return extractChar();
    }
  }

  int tokenValue() const { return _tokenValue; }

  int skipLeadingWhiteSpace()
  {
    for (; (buffer[pos] == ' ' || buffer[pos] == '\t') && pos < buffer.length(); ++pos)
      ;
    return position();
  }

  int position() const { return pos; }

  char currentChar() { return buffer[pos]; }

  // extractX: extract X and set position right after X
  int extractNumber()
  {
    int posBegin = position();
    for (; isdigit(buffer[pos]); ++pos)
      ;
    return stoi(buffer.substr(posBegin, pos - posBegin));
  }

  string extractAtom()
  {
    int posBegin = position();
    for (; isalnum(buffer[pos]); ++pos)
      ;
    return buffer.substr(posBegin, pos - posBegin);
  }

  string extractAtomSC()
  {
    int posBegin = position();
    for (; isSpecialCh(buffer[pos]); ++pos)
      ;
    return buffer.substr(posBegin, pos - posBegin);
  }

  string extractVar()
  {
    int posBegin = position();
    for (; isalnum(buffer[pos]) || buffer[pos] == '_'; ++pos)
      ;
    return buffer.substr(posBegin, pos - posBegin);
  }

  char extractChar()
  {
    return buffer[pos++];
  }

private:
  string buffer;
  int pos;
  int _tokenValue;

  // case-based populating symtable and setting _tokenValue
  template <int TokenType>
  void processToken(string const &s)
  {
    int val = -1;
    if (symbolExist(s, val))
    {
      _tokenValue = val;
    }
    else
    {
      symtable.push_back(pair<string, int>(s, TokenType));
      _tokenValue = symtable.size() - 1; // index to symtable
    }
  }
};

#endif