#include "list.h"
#include "iterator.h"

Iterator<Term> *List::createIterator() { return new ListIterator<Term>(this); }
Iterator<Term> *List::createDFSIterator() { return new DFSIterator<Term>(this); }