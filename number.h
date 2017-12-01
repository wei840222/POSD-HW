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

  private:
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

    const string _symbol;
};

#endif