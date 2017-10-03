#ifndef UTTERM_H
#define UTTERM_H

#include "include/atom.h"
#include "include/number.h"
#include "include/variable.h"

//test Number.value()
TEST (Number,ctor)
{
    Number one(1);
    ASSERT_EQ(one.value(), "1");
}

//test Number.symbol()
TEST (Number, symbol)
{
    Number two(2);
    ASSERT_EQ(two.symbol(), "2");
}

//?- 25=25.
//true.
TEST (Number, matchSuccess)
{
    Number twentyFive(25);
    ASSERT_TRUE(twentyFive.match(twentyFive));
}

//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue)
{
    Number twentyFive(25), zero(0);
    ASSERT_FALSE(twentyFive.match(zero));
}

//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant)
{
    Number twentyFive(25);
    Atom tom("tom");
    ASSERT_FALSE(twentyFive.match(tom));
}

//?- 25=X.
//true.
TEST (Number, matchSuccessToVar)
{
    Number twentyFive(25);
    Variable X("X");
    ASSERT_TRUE(twentyFive.match(X));
    ASSERT_EQ(X.value(), twentyFive.value());
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant)
{
    Atom tom("tom");
    Number twentyFive(25);
    ASSERT_FALSE(tom.match(twentyFive));
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar)
{
    Atom tom("tom");
    Variable X("X");
    ASSERT_TRUE(tom.match(X));
    ASSERT_EQ(X.value(), tom.value());
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant)
{

}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant)
{

}

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber)
{
 
}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers)
{

}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber)
{

}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2)
{

}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom)
{

}

#endif