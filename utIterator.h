#ifndef UTITERATOR_H
#define UTITERATOR_H

#include "iterator.h"
#include <gtest/gtest.h>

TEST(iterator, first)
{
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
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

    itStruct2->first();
    EXPECT_EQ("X", itStruct2->currentItem()->symbol());
    EXPECT_FALSE(itStruct2->isDone());

    itStruct2->next();
    EXPECT_EQ("2", itStruct2->currentItem()->symbol());
    EXPECT_FALSE(itStruct2->isDone());

    itStruct2->next();
    EXPECT_TRUE(itStruct2->isDone());
}

    // TEST(iterator, firstList) {
    //     Number one(1);
    //     Variable X("X");
    //     Variable Y("Y");
    //     Number two(2);
    //     Struct t(Atom("t"), { &X, &two });
    //     List l({ &one, &t, &Y });
    //     ListIterator it(&l);
    //     Iterator* itList = &it;
    //     itList->first();
    //     ASSERT_EQ("1", itList->currentItem()->symbol());
    //     ASSERT_FALSE(itList->isDone());
    //     itList->next();
    //     ASSERT_EQ("t(X, 2)", itList->currentItem()->symbol());
    //     ASSERT_FALSE(itList->isDone());
    //     itList->next();
    //     ASSERT_EQ("Y", itList->currentItem()->symbol());
    //     itList->next();
    //     ASSERT_TRUE(itList->isDone());
    // }

    // TEST(iterator, NullIterator){
    //   Number one(1);
    //   NullIterator nullIterator(&one);
    //   nullIterator.first();
    //   ASSERT_TRUE(nullIterator.isDone());
    //   Iterator * it = one.createIterator();
    //   it->first();
    //   ASSERT_TRUE(it->isDone());
    // }

#endif