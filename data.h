#ifndef DATA_H
#define DATA_H

#include <string>
using std::string;

class Data
{
public:
    virtual const string symbol() = 0;
    virtual const string value() = 0;
    virtual const bool match(Data &data) = 0;
};

#endif