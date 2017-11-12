#ifndef UTTOKEN_H
#define UTTOKEN_H

#include "token.h"

TEST(Token, createTokenNONE)
{
    Token t;
    EXPECT_EQ(t.type(), Token::NONE);
    EXPECT_EQ(t.value(), "");
}

TEST(Token, createTokenATOM)
{
    Token t(Token::ATOM, "fuck");
    EXPECT_EQ(t.type(), Token::ATOM);
    EXPECT_EQ(t.value(), "fuck");
}

TEST(Token, createTokenNUMBER)
{
    Token t(Token::NUMBER, "123");
    EXPECT_EQ(t.type(), Token::NUMBER);
    EXPECT_EQ(t.valueToDouble(), 123);
}

#endif