#include "list.h"
#include "iterator.h"

Iterator<Term *> *List::createIterator() { return new ListIterator<Term *>(this); }
DFSIterator<Term *> *List::createDFSIterator() { return new DFSIterator<Term *>(this); }
BFSIterator<Term *> *List::createBFSIterator() { return new BFSIterator<Term *>(this); }