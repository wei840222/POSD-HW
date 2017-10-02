#ifndef UTTERM_H
#define UTTERM_H

#include "include/number.h"

//test Number.value()
TEST (Number,ctor)
{
    Number one("one", 1);
    ASSERT_EQ(one.value(), "1");
}

//test Number.symbol()
TEST (Number, symbol)
{
    Number two("two", 2);
    ASSERT_EQ(two.symbol(), "two");
}

//?- 25=25.
//true.
TEST (Number, matchSuccess)
{
    Number n("n", 25);
    ASSERT_TRUE(n.match(n));
}

//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue)
{
    Number n1("n1", 25), n2("n2", 0);
    ASSERT_FALSE(n1.match(n2));
}

//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant)
{

}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar)
{
  
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant)
{

}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar)
{

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