#include "struct.h"
#include "iterator.h"

Iterator<Term> *Struct::createIterator() { return new StructIterator<Term>(this); }
DFSIterator<Term> *Struct::createDFSIterator() { return new DFSIterator<Term>(this); }
BFSIterator<Term> *Struct::createBFSIterator() { return new BFSIterator<Term>(this); }