#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "term.h"
#include "atom.h"

class Structure
{
public:
    Structure(Atom name, Term term[]):_name(name), _term(term){}
    Atom name(){return _name;}
    Term* term(){return _term;}

private:
    Atom _name;
    Term* _term;
};

#endif