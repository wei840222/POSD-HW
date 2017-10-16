#ifndef NUMBER_H
#define NUMBER_H

#include "term.h"
#include "variable.h"
#include <string>
using std::string;

class Number : public Term
{
  public:
    Number(double d) : _symbol(numToString(d)) {}
    string symbol() const { return _symbol; }
    bool match(Term &term) { return symbol() == term.symbol(); }
    bool match(Variable &variable)
    {
        if (variable.isAssignable())
        {
            variable.setValue(symbol());
            variable.disAssignable();
            return true;
        }
        else
        {
            return symbol() == variable.value();
        }
    }

  private:
    const string _symbol;

    string numToString(double d)
    {
        string num = std::to_string(d);
        int i = num.size() - 1;
        while (num[i] == '0')
        {
            i--;
        }
        if (num[i] == '.')
        {
            i--;
        }
        num.resize(i + 1);
        return num;
    }
};

#endif