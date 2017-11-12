#ifndef UTSCANNER_H
#define UTSCANNER_H

#include "scanner.h"

TEST(ScannerTest, nextTokenEOS)
{
  //---------------01234
  Scanner scanner("    ");
  EXPECT_EQ(0, scanner.position());
  Token *tok = scanner.nextToken();
  EXPECT_EQ(Token::EOS, tok->type());
  EXPECT_EQ("", tok->value());
  tok = scanner.currentToken();
  EXPECT_EQ(Token::EOS, tok->type());
  EXPECT_EQ("", tok->value());
  EXPECT_EQ(4, scanner.position());
}

TEST(ScannerTest, nextTokenEOS2)
{
  //---------------0
  Scanner scanner("");
  EXPECT_EQ(0, scanner.position());
  Token *tok = scanner.nextToken();
  EXPECT_EQ(Token::EOS, tok->type());
  EXPECT_EQ("", tok->value());
  EXPECT_EQ(0, scanner.position());
}

TEST(ScannerTest, nextTokenNumber)
{
  //---------------0123
  Scanner scanner("135");
  EXPECT_EQ(0, scanner.position());
  Token *tok = scanner.nextToken();
  EXPECT_EQ(Token::NUMBER, tok->type());
  EXPECT_EQ(135, tok->valueToDouble());
  EXPECT_EQ(3, scanner.position());
}

TEST(ScannerTest, nextTokenAtom)
{
  //---------------0123
  Scanner scanner("tom");
  EXPECT_EQ(0, scanner.position());
  Token *tok = scanner.nextToken();
  EXPECT_EQ(Token::ATOM, tok->type());
  EXPECT_EQ("tom", tok->value());
  EXPECT_EQ(3, scanner.position());
}

TEST(ScannerTest, nextTokenVar)
{
  //---------------01234
  Scanner scanner("Date");
  EXPECT_EQ(0, scanner.position());
  Token *tok = scanner.nextToken();
  EXPECT_EQ(Token::VAR, tok->type());
  EXPECT_EQ("Date", tok->value());
  EXPECT_EQ(4, scanner.position());
}

TEST(ScannerTest, nextTokenChar)
{
  //---------------01234
  Scanner scanner("   (");
  Token *tok = scanner.nextToken();
  EXPECT_EQ(Token::NONE, tok->type());
  EXPECT_EQ("(", tok->value());
  EXPECT_EQ(4, scanner.position());
  tok = scanner.nextToken();
  EXPECT_EQ(Token::EOS, tok->type());
  EXPECT_EQ("", tok->value());
  EXPECT_EQ(4, scanner.position());
}

TEST(ScannerTest, nextTokenChar2)
{
  //---------------01234
  Scanner scanner("   []");
  Token *tok = scanner.nextToken();
  EXPECT_EQ(Token::NONE, tok->type());
  EXPECT_EQ("[", tok->value());
  EXPECT_EQ(4, scanner.position());
  tok = scanner.nextToken();
  EXPECT_EQ(Token::NONE, tok->type());
  EXPECT_EQ("]", tok->value());
  EXPECT_EQ(5, scanner.position());
  tok = scanner.nextToken();
  EXPECT_EQ(Token::EOS, tok->type());
  EXPECT_EQ("", tok->value());
  EXPECT_EQ(5, scanner.position());
}

TEST(ScannerTest, nextTokenAtomSC)
{
  //---------------01234567-890
  Scanner scanner(".*-><&$@\\?");
  EXPECT_EQ(0, scanner.position());
  Token *tok = scanner.nextToken();
  EXPECT_EQ(Token::ATOMSC, tok->type());
  EXPECT_EQ(".*-><&$@\\?", tok->value());
  EXPECT_EQ(10, scanner.position());
}

#endif
