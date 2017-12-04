#include "struct.h"
#include "iterator.h"

Iterator<Term *> *Struct::createIterator() { return new StructIterator<Term *>(this); }