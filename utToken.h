#ifndef UTTOKEN_H
#define UTTOKEN_H

#include "token.h"

TEST(Token, createTokenNONE)
{
    Token t;
    EXPECT_EQ(Token::NONE, t.type());
    EXPECT_EQ("", t.value());
}

TEST(Token, createTokenATOM)
{
    Token t(Token::ATOM, "fuck");
    EXPECT_EQ(Token::ATOM, t.type());
    EXPECT_EQ("fuck", t.value());
}

TEST(Token, createTokenNUMBER)
{
    Token t(Token::NUMBER, "123");
    EXPECT_EQ(Token::NUMBER, t.type());
    EXPECT_EQ(123, t.valueToDouble());
}

#endif