#include "list.h"
#include "iterator.h"

Iterator<List> *List::createIterator() { return new Iterator<List>(this); }