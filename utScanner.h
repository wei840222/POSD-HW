#ifndef UTSCANNER_H
#define UTSCANNER_H

#include "scanner.h"

TEST(ScannerTest, position)
{
  // one, two, three spaces
  //---------------012345678901234567890
  Scanner scanner(" 12345,  tom,   Date");
  EXPECT_EQ(0, scanner.position());

  EXPECT_EQ(1, scanner.skipLeadingWhiteSpace());
  EXPECT_TRUE(isdigit(scanner.currentChar()));
  EXPECT_EQ("12345", scanner.extractNumber());
  EXPECT_EQ(6, scanner.position());

  EXPECT_EQ(',', scanner.extractChar());
  EXPECT_EQ(7, scanner.position());

  EXPECT_EQ(9, scanner.skipLeadingWhiteSpace());
  EXPECT_TRUE(islower(scanner.currentChar()));
  EXPECT_EQ("tom", scanner.extractAtom());
  EXPECT_EQ(12, scanner.position());

  EXPECT_EQ(',', scanner.extractChar());
  EXPECT_EQ(13, scanner.position());

  EXPECT_EQ(16, scanner.skipLeadingWhiteSpace());
  EXPECT_TRUE(isupper(scanner.currentChar()));
  EXPECT_EQ("Date", scanner.extractVar());
  EXPECT_EQ(20, scanner.position());
}

TEST(ScannerTest, nextTokenNONE)
{
  //---------------01234
  Scanner scanner("    ");
  EXPECT_EQ(0, scanner.position());
  Token *tok = scanner.nextToken();
  EXPECT_EQ(Token::NONE, tok->type());
  EXPECT_EQ("", tok->value());
  tok = scanner.currentToken();
  EXPECT_EQ(Token::NONE, tok->type());
  EXPECT_EQ("", tok->value());
  EXPECT_EQ(4, scanner.position());
}

TEST(ScannerTest, nextTokenNONE2)
{
  //---------------0
  Scanner scanner("");
  EXPECT_EQ(0, scanner.position());
  Token *tok = scanner.nextToken();
  EXPECT_EQ(Token::NONE, tok->type());
  EXPECT_EQ("", tok->value());
  EXPECT_EQ(0, scanner.position());
  tok = scanner.currentToken();
  EXPECT_EQ(Token::NONE, tok->type());
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
  scanner.nextToken();
  Token *tok = scanner.currentToken();
  EXPECT_EQ(Token::ATOM, tok->type());
  EXPECT_EQ("tom", tok->value());
  EXPECT_EQ(3, scanner.position());
}

  // TEST_F(ScannerTest, nextTokenVar) {
  //   //---------------01234
  //   Scanner scanner("Date");
  //   EXPECT_EQ(0, scanner.position());
  //   int token = scanner.nextToken();
  //   EXPECT_EQ(VAR, token);
  //   EXPECT_EQ(0, scanner.tokenValue());
  //   EXPECT_EQ(4, scanner.position());
  //   EXPECT_EQ("Date", symtable[0].first);
  //   EXPECT_EQ(VAR, symtable[0].second);
  // }

  // TEST_F(ScannerTest, nextTokenChar) {
  //   //---------------01234
  //   Scanner scanner("   (");
  //   int token = scanner.nextToken();
  //   EXPECT_EQ('(', token);
  //   EXPECT_EQ(NONE, scanner.tokenValue());
  //   EXPECT_EQ(4, scanner.position());
  //   token = scanner.nextToken();
  //   EXPECT_EQ(EOS, token);
  //   EXPECT_EQ(NONE, scanner.tokenValue());
  //   EXPECT_EQ(4, scanner.position());
  // }

  // TEST_F(ScannerTest, nextTokenChar2) {
  //   //---------------01234
  //   Scanner scanner("   []");
  //   int token = scanner.nextToken();
  //   EXPECT_EQ('[', token);
  //   EXPECT_EQ(NONE, scanner.tokenValue());
  //   EXPECT_EQ(4, scanner.position());
  //   token = scanner.nextToken();
  //   EXPECT_EQ(']', token);
  //   EXPECT_EQ(NONE, scanner.tokenValue());
  //   EXPECT_EQ(5, scanner.position());
  //   token = scanner.nextToken();
  //   EXPECT_EQ(EOS, token);
  //   EXPECT_EQ(NONE, scanner.tokenValue());
  //   EXPECT_EQ(5, scanner.position());
  // }

  // TEST_F(ScannerTest, nextTokenAtomSC) {
  //   //---------------01234567-890
  //   Scanner scanner(".*-><&$@\\?");
  //   EXPECT_EQ(0, scanner.position());
  //   int token = scanner.nextToken();
  //   EXPECT_EQ(ATOMSC, token);
  //   EXPECT_EQ(0, scanner.tokenValue());
  //   EXPECT_EQ(10, scanner.position());
  //   EXPECT_EQ(".*-><&$@\\?", symtable[0].first);
  //   EXPECT_EQ(ATOMSC, symtable[0].second);
  // }

#endif
