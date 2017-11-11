#ifndef UTTOKEN_H
#define UTTOKEN_H

#include "token.h"

TEST(Token, createTokenNONE)
{
    Token t;
    EXPECT_EQ(t.type(), Token::NONE);
    EXPECT_EQ(t.value(), "");
}

#endif