#ifndef UTITERATOR_H
#define UTITERATOR_H

#include "atom.h"
#include "number.h"
#include "variable.h"
#include "iterator.h"
#include <gtest/gtest.h>

//1
TEST(Iterator, nullIterator)
{
    Number one(1);
    Iterator<Term> *itr = one.createIterator();
    EXPECT_EQ("1", itr->currentItem()->symbol());
    EXPECT_TRUE(itr->isDone());
}

//s(1, t(X, 2), Y)
TEST(Iterator, structIterator)
{
    Number one(1), two(2);
    Variable X("X"), Y("Y");
    Struct t(Atom("t"), {&X, &two});
    Struct s(Atom("s"), {&one, &t, &Y});

    Iterator<Struct> *itr = s.createIterator();
    EXPECT_EQ("1", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("t(X, 2)", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("Y", itr->currentItem()->symbol());

    itr->next();
    EXPECT_TRUE(itr->isDone());
}

//s(1, t(X, 2), Y)
TEST(Iterator, nestedStructIterator)
{
    Number one(1), two(2);
    Variable X("X"), Y("Y");
    Struct t(Atom("t"), {&X, &two});
    Struct s(Atom("s"), {&one, &t, &Y});

    Iterator<Struct> *itr = s.createIterator();
    itr->next();
    Struct *s2 = dynamic_cast<Struct *>(itr->currentItem());
    Iterator<Struct> *itr2 = s2->createIterator();

    EXPECT_EQ("X", itr2->currentItem()->symbol());
    EXPECT_FALSE(itr2->isDone());

    itr2->next();
    EXPECT_EQ("2", itr2->currentItem()->symbol());
    EXPECT_FALSE(itr2->isDone());

    itr2->next();
    EXPECT_TRUE(itr2->isDone());
}

    // TEST(Iterator, firstList)
    // {
    //     Number one(1), two(2);
    //     Variable X("X"), Y("Y");
    //     Struct t(Atom("t"), {&X, &two});
    //     List l({&one, &t, &Y});

    //     Iterator<Term *> *itList = l.createIterator();

    //     EXPECT_EQ("1", itList->currentItem()->symbol());
    //     EXPECT_FALSE(itList->isDone());

    //     itList->next();
    //     EXPECT_EQ("t(X, 2)", itList->currentItem()->symbol());
    //     EXPECT_FALSE(itList->isDone());

    //     itList->next();
    //     EXPECT_EQ("Y", itList->currentItem()->symbol());

    //     itList->next();
    //     EXPECT_TRUE(itList->isDone());
    // }

#endif