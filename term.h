#ifndef TERM_H
#define TERM_H

#include <string>
using std::string;

class Term
{
public:
    virtual string symbol() = 0;
    virtual string value() = 0;
    virtual bool match(Term& term) = 0;
};

#endif