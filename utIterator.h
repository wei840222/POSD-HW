#ifndef UTITERATOR_H
#define UTITERATOR_H

#include "atom.h"
#include "number.h"
#include "variable.h"
#include "iterator.h"
#include <gtest/gtest.h>

TEST(Iterator, nullIterator)
{
    Number one(1);
    Iterator<Term> *itr = one.createIterator();
    EXPECT_EQ("1", itr->currentItem()->symbol());
    EXPECT_TRUE(itr->isDone());
}

//s(1, t(X, 2), Y)
TEST(Iterator, iteratorStruct)
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

    // TEST(Iterator, nested_structIterator)
    // {
    //     Number one(1), two(2);
    //     Variable X("X"), Y("Y");
    //     Struct t(Atom("t"), {&X, &two});
    //     Struct s(Atom("s"), {&one, &t, &Y});

    //     Iterator<Term *> *itStruct = s.createIterator();
    //     itStruct->next();
    //     Struct *s2 = dynamic_cast<Struct *>(itStruct->currentItem());
    //     Iterator<Term *> *itStruct2 = s2->createIterator();

    //     EXPECT_EQ("X", itStruct2->currentItem()->symbol());
    //     EXPECT_FALSE(itStruct2->isDone());

    //     itStruct2->next();
    //     EXPECT_EQ("2", itStruct2->currentItem()->symbol());
    //     EXPECT_FALSE(itStruct2->isDone());

    //     itStruct2->next();
    //     EXPECT_TRUE(itStruct2->isDone());
    // }

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