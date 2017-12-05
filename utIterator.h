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
    EXPECT_EQ("1", itr->currentTerm()->symbol());
    EXPECT_TRUE(itr->isDone());
}

//s(1, t(X, 2), Y)
TEST(Iterator, structIterator)
{
    Number one(1), two(2);
    Variable X("X"), Y("Y");
    Struct t(Atom("t"), {&X, &two});
    Struct s(Atom("s"), {&one, &t, &Y});

    Iterator<Term> *itr = s.createIterator();
    EXPECT_EQ("1", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("t(X, 2)", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("Y", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_TRUE(itr->isDone());

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

    Iterator<Term> *itr = s.createIterator();
    itr->next();
    Struct *s2 = dynamic_cast<Struct *>(itr->currentItem());
    Iterator<Term> *itr2 = s2->createIterator();

    EXPECT_EQ("X", itr2->currentItem()->symbol());
    EXPECT_FALSE(itr2->isDone());

    itr2->next();
    EXPECT_EQ("2", itr2->currentItem()->symbol());
    EXPECT_FALSE(itr2->isDone());

    itr2->next();
    EXPECT_TRUE(itr2->isDone());
}

//[1, t(X, 2), Y]
TEST(Iterator, listIterator)
{
    Number one(1), two(2);
    Variable X("X"), Y("Y");
    Struct t(Atom("t"), {&X, &two});
    List l({&one, &t, &Y});

    Iterator<Term> *itr = l.createIterator();

    EXPECT_EQ("1", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("t(X, 2)", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("Y", itr->currentItem()->symbol());

    itr->next();
    EXPECT_TRUE(itr->isDone());

    itr->next();
    EXPECT_TRUE(itr->isDone());
}

//s(1, t(2, 3), X, [a, b], 4, Y)
TEST(DFSIterator, DFSStructIterator)
{
    Atom a("a"), b("b");
    Number one(1), two(2), three(3), four(4);
    Variable X("X"), Y("Y");
    Struct t(Atom("t"), {&two, &three});
    List l({&a, &b});
    Struct s(Atom("s"), {&one, &t, &X, &l, &four, &Y});

    DFSIterator<Term> *itr = s.createDFSIterator();
    EXPECT_EQ("1", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("t(2, 3)", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("2", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("3", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("X", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("[a, b]", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("a", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("b", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("4", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("Y", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_TRUE(itr->isDone());
    
    itr->next();
    EXPECT_TRUE(itr->isDone());
}

//[1, t(2, 3), X, [a, b], 4, Y]
TEST(DFSIterator, DFSListIterator)
{
    Atom a("a"), b("b");
    Number one(1), two(2), three(3), four(4);
    Variable X("X"), Y("Y");
    Struct t(Atom("t"), {&two, &three});
    List l({&a, &b});
    List l2({&one, &t, &X, &l, &four, &Y});

    DFSIterator<Term> *itr = l2.createDFSIterator();
    EXPECT_EQ("1", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("t(2, 3)", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("2", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("3", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("X", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("[a, b]", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("a", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("b", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("4", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("Y", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_TRUE(itr->isDone());
    
    itr->next();
    EXPECT_TRUE(itr->isDone());
}

//s(1, t(2, 3), X, [a, b], 4, Y)
TEST(BFSIterator, BFSStructIterator)
{
    Atom a("a"), b("b");
    Number one(1), two(2), three(3), four(4);
    Variable X("X"), Y("Y");
    Struct t(Atom("t"), {&two, &three});
    List l({&a, &b});
    Struct s(Atom("s"), {&one, &t, &X, &l, &four, &Y});

    BFSIterator<Term> *itr = s.createBFSIterator();
    EXPECT_EQ("1", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("t(2, 3)", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("X", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("[a, b]", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("4", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("Y", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("2", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("3", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("a", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_EQ("b", itr->currentItem()->symbol());
    EXPECT_FALSE(itr->isDone());

    itr->next();
    EXPECT_TRUE(itr->isDone());
    
    itr->next();
    EXPECT_TRUE(itr->isDone());
}

#endif