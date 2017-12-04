#ifndef UTITERATOR_H
#define UTITERATOR_H

#include "iterator.h"

TEST(iterator, first)
{
    Number one(1), two(2);
    Variable X("X"), Y("Y");
    Struct t(Atom("t"), {&X, &two});
    Struct s(Atom("s"), {&one, &t, &Y});

    Iterator<Term *> *itStruct = s.createIterator();
    EXPECT_EQ("1", itStruct->currentItem()->symbol());
    EXPECT_FALSE(itStruct->isDone());

    itStruct->next();
    EXPECT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
    EXPECT_FALSE(itStruct->isDone());

    itStruct->next();
    EXPECT_EQ("Y", itStruct->currentItem()->symbol());

    itStruct->next();
    EXPECT_TRUE(itStruct->isDone());
}

TEST(iterator, nested_iterator)
{
    Number one(1), two(2);
    Variable X("X"), Y("Y");
    Struct t(Atom("t"), {&X, &two});
    Struct s(Atom("s"), {&one, &t, &Y});

    Iterator<Term *> *itStruct = s.createIterator();
    itStruct->next();
    Struct *s2 = dynamic_cast<Struct *>(itStruct->currentItem());
    Iterator<Term *> *itStruct2 = s2->createIterator();

    EXPECT_EQ("X", itStruct2->currentItem()->symbol());
    EXPECT_FALSE(itStruct2->isDone());

    itStruct2->next();
    EXPECT_EQ("2", itStruct2->currentItem()->symbol());
    EXPECT_FALSE(itStruct2->isDone());

    itStruct2->next();
    EXPECT_TRUE(itStruct2->isDone());
}

TEST(iterator, firstList)
{
    Number one(1), two(2);
    Variable X("X"), Y("Y");
    Struct t(Atom("t"), {&X, &two});
    List l({&one, &t, &Y});

    Iterator<Term *> *itList = l.createIterator();

    EXPECT_EQ("1", itList->currentItem()->symbol());
    EXPECT_FALSE(itList->isDone());

    itList->next();
    EXPECT_EQ("t(X, 2)", itList->currentItem()->symbol());
    EXPECT_FALSE(itList->isDone());

    itList->next();
    EXPECT_EQ("Y", itList->currentItem()->symbol());

    itList->next();
    EXPECT_TRUE(itList->isDone());
}

TEST(iterator, NullIterator)
{
    Number one(1);
    NullIterator<Term *> nullIterator(&one);
    EXPECT_TRUE(nullIterator.isDone());

    Iterator<Term *> *it = one.createIterator();
    EXPECT_TRUE(it->isDone());
}

#endif