#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <string>
using std::string;

class DataAccess
{
public:
    virtual const string symbol() = 0;
    virtual const string value() = 0;
    virtual const bool match(DataAccess& dataAccess) = 0;
};

#endif