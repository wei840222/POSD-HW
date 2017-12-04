#include "struct.h"
#include "iterator.h"

Iterator<Struct> *Struct::createIterator() { return new Iterator<Struct>(this); }