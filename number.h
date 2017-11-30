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
    bool match(Term &term) { return symbol() == term.value(); }
    bool match(Variable &variable)
    {
        if (variable.isAssignable())
        {
            variable.setValue(this);
            return true;
        }
        else
            return symbol() == variable.value();
    }

  private:
    const string _symbol;

    string numToString(double d)
    {
        string num = std::to_string(d);
        int i = num.size();
        while (num[--i] == '0')
            ;
        if (num[i] == '.')
            i--;
        num.resize(i + 1);
        return num;
    }
};

#endif