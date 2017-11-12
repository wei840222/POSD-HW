#ifndef UTPARSER_H
#define UTPARSER_H

#include "term.h"
#include "struct.h"
#include "parser.h"
#include "scanner.h"

TEST(ParserTest, createTerm_Var)
{
  Parser parser(Scanner("X"));
  EXPECT_EQ("X", parser.createTerm()->symbol());
}

TEST(ParserTest, createTerm_Num)
{
  Parser parser(Scanner("123"));
  EXPECT_EQ("123", parser.createTerm()->symbol());
}

TEST(ParserTest, createTerm_Atom)
{
  Parser parser(Scanner("tom"));
  EXPECT_EQ("tom", parser.createTerm()->symbol());
}

TEST(ParserTest, createTerms)
{
  Parser parser(Scanner("1, X, tom"));
  vector<Term *> *terms = parser.createTerms();
  EXPECT_EQ("1", (*terms)[0]->symbol());
  EXPECT_EQ("X", (*terms)[1]->symbol());
  EXPECT_EQ("tom", (*terms)[2]->symbol());
}

TEST(ParserTest, createStruct)
{
  Parser parser(Scanner("s(1, X, tom)"));
  EXPECT_EQ("s(1, X, tom)", parser.createTerm()->symbol());
}

// Given there is string: " 12345,  tom" in scanner.
// When parser parses all terms via scanner.
// Then it should return two terms, one is "12345", another is "tom".
TEST(ParserTest, listOfTermsTwo)
{
  Parser parser(Scanner(" 12345,  tom"));
  vector<Term *> *terms = parser.createTerms();
  EXPECT_EQ("12345", (*terms)[0]->symbol());
  EXPECT_EQ("tom", (*terms)[1]->symbol());
}

// Given there is string: "point(1, X, z(1,2,3))" in scanner.
// When parser parses all terms via scanner.
// Then it should return a Struct.
// And #symbol() of Strcut should return "point(1, X, z(1,2,3))".
TEST(ParserTest, parseStructOfStruct)
{
  Parser parser(Scanner("point(1, X, z(1,2,3))"));
  ASSERT_EQ("point(1, X, z(1, 2, 3))", parser.createTerm()->symbol());
}

// Given there is string: " 12345,  67" in scanner.
// When parser parses all terms via scanner.
// Then it should return two terms, one is "12345", another is "67".
TEST(ParserTest, listOfTermsTwoNumbers)
{
  Parser parser(Scanner(" 12345,  67"));
  vector<Term *> *terms = parser.createTerms();
  EXPECT_EQ("12345", (*terms)[0]->symbol());
  EXPECT_EQ("67", (*terms)[1]->symbol());
}

// Given there is string: "point(1, X, z)" in scanner.
// When parser parses all terms via scanner.
// Then it should return a Struct.
// And #symbol() of Strcut should return "point(1, X, z)".
TEST(ParserTest, parseStructThreeArgs)
{
  Parser parser(Scanner("point(1, X, z)"));
  EXPECT_EQ("point(1, X, z)", parser.createTerm()->symbol());
}

// Given there is string: "   [   ]" in scanner.
// When parser parses all terms via scanner.
// Then it should return a List.
// And #symbol() of List should return "[]".
TEST(ParserTest, parseListEmpty)
{

  Parser parser(Scanner("   [   ]"));
  EXPECT_EQ("[]", parser.createTerm()->symbol());
}

// Given there is string: "_date" in scanner.
// When parser parses all terms via scanner.
// Then it should return a Variable.
// And #symbol() of Variable should return "_date".
TEST(ParserTest, parseVar)
{
  Parser parser(Scanner("_date"));
  EXPECT_EQ("_date", parser.createTerm()->symbol());
}

// Given there is not string in scanner.
// When parser parses all terms via scanner.
// Then it should return nothing.
TEST(ParserTest, listOfTermsEmpty)
{
  Scanner scanner;
  Parser parser(scanner);
  EXPECT_EQ(nullptr, parser.createTerm());
}

// Given there is string: "s(s(s(s(1))))" in scanner.
// When parser parses all terms via scanner.
// Then it should return a Struct.
// And #symbol() of Strcut should return "s(s(s(s(1))))".
TEST(ParserTest, parseStructOfStructAllTheWay)
{
  Parser parser(Scanner("s(s(s(s(1))))"));
  EXPECT_EQ("s(s(s(s(1))))", parser.createTerm()->symbol());
}

// Given there is string: "   [  [1], [] ]" in scanner.
// When parser parses all terms via scanner.
// Then it should return a List.
// And #symbol() of List should return "[[1], []]".
TEST(ParserTest, parseListOfLists)
{
  Parser parser(Scanner("   [  [1], [] ]"));
  EXPECT_EQ("[[1], []]", parser.createTerm()->symbol());
}

// Given there is string: "   [  [1], [], s(s(1)) ]   " in scanner.
// When parser parses all terms via scanner.
// Then it should return a List.
// And #symbol() of List should return "[[1], [], s(s(1))]".
TEST(ParserTest, parseListOfListsAndStruct)
{
  Parser parser(Scanner("   [  [1], [], s(s(1)) ]   "));
  EXPECT_EQ("[[1], [], s(s(1))]", parser.createTerm()->symbol());
}

// Given there is string: "   [1, 2]" in scanner.
// When parser parses all terms via scanner.
// Then it should return a List.
// And #symbol() of List should return "[1, 2]".
TEST(ParserTest, parseList)
{
  Parser parser(Scanner("   [1, 2]"));
  EXPECT_EQ("[1, 2]", parser.createTerm()->symbol());
}

  // // Given there is string: "[1,2)" in scanner.
  // // When parser parses all terms via scanner.
  // // Then it should return a string: "unexpected token" as exception.
  // TEST_F(ParserTest, illegal1)
  // {
  //   Scanner scanner("[1,2)");
  //   Parser parser(scanner);
  //   try
  //   {
  //     parser.createTerm();
  //   }
  //   catch(string e)
  //   {
  //     ASSERT_EQ("unexpected token", e);
  //   }
  // }

  // // Given there is string: ".(1,[])" in scanner.
  // // When parser parses all terms via scanner.
  // // Then it should return a Struct which contains two terms.
  // // And #arity() of the Struct should be 2.
  // // And #symbol() of Struct should return ".(1, [])".
  // // And the first term should be number: "1", the second term should be another List: "[]".
  // TEST_F(ParserTest, ListAsStruct)
  // {
  //   Scanner scanner(".(1,[])");
  //   Parser parser(scanner);
  //   Struct *stuct = dynamic_cast<Struct *>(parser.createTerm());
  //   EXPECT_EQ(".(1, [])", stuct->symbol());
  //   EXPECT_EQ(2, stuct->arity());
  //   EXPECT_EQ("1", stuct->args(0)->symbol());
  //   EXPECT_EQ("[]", stuct->args(1)->symbol());
  // }

  // // Given there is string: ".(2,.(1,[]))" in scanner.
  // // When parser parses all terms via scanner.
  // // Then it should return a Struct which contains two terms.
  // // And #arity() of the Struct should be 2.
  // // And #symbol() of Struct should return ".(2, .(1, []))"
  // // And the first term should be number: "2", the second term should be another Strcut: ".(1, [])".
  // TEST_F(ParserTest, ListAsStruct2)
  // {
  //   Scanner scanner(".(2,.(1,[]))");
  //   Parser parser(scanner);
  //   Struct *stuct = dynamic_cast<Struct *>(parser.createTerm());
  //   EXPECT_EQ(".(2, .(1, []))", stuct->symbol());
  //   EXPECT_EQ(2, stuct->arity());
  //   EXPECT_EQ("2", stuct->args(0)->symbol());
  //   EXPECT_EQ(".(1, [])", stuct->args(1)->symbol());
  // }

  // // Given there is string: "s(s(s(s(1)))), b(1,2,3)" in scanner.
  // // When parser parses all terms via scanner.
  // // Then it should return two Struct.
  // // And #symbol() of the first Strcut should return "s(s(s(s(1))))".
  // // And #symbol() of the second Strcut should return "b(1, 2, 3)".
  // TEST_F(ParserTest, parseStructOfStructAllTheWay2)
  // {
  //   Scanner scanner("s(s(s(s(1)))), b(1,2,3)");
  //   Parser parser(scanner);
  //   vector<Term *> terms = parser.getArgs();
  //   ASSERT_EQ("s(s(s(s(1))))", terms[0]->symbol());
  //   ASSERT_EQ("b(1, 2, 3)", terms[1]->symbol());
  // }

  // // Given there is string: "point()" in scanner.
  // // When parser parses all terms via scanner.
  // // Then it should return a Struct.
  // // And #symbol() of Strcut should return "point()".
  // TEST_F(ParserTest, parseStructNoArg)
  // {
  //   Scanner scanner("point()");
  //   Parser parser(scanner);
  //   ASSERT_EQ("point()", parser.createTerm()->symbol());
  // }

  // // Given there is string: " 12345,  tom,   Date" in scanner.
  // // When parser parses all terms via scanner.
  // // Then it should return three terms: "12345", "tom" and "Date".
  // TEST_F(ParserTest, listOfTermsThree)
  // {
  //   Scanner scanner(" 12345,  tom,   Date");
  //   Parser parser(scanner);
  //   vector<Term *> terms = parser.getArgs();
  //   ASSERT_EQ("12345", terms[0]->symbol());
  //   ASSERT_EQ("tom", terms[1]->symbol());
  //   ASSERT_EQ("Date", terms[2]->symbol());
  // }

  // // Given there is string: "point(11,12)" in scanner.
  // // When parser parses all terms via scanner.
  // // Then it should return a Struct.
  // // And #symbol() of Strcut should return "point(11, 12)".
  // TEST_F(ParserTest, parseStructTwoArgs)
  // {
  //   Scanner scanner("point(11,12)");
  //   Parser parser(scanner);
  //   ASSERT_EQ("point(11, 12)", parser.createTerm()->symbol());
  // }

  // // Given there is string: "...(11,12)" in scanner.
  // // When parser parses all terms via scanner.
  // // Then it should return a Struct.
  // // And #symbol() of Strcut should return "...(11, 12)".
  // TEST_F(ParserTest, parseStructDOTSTwoArgs)
  // {
  //   Scanner scanner("...(11,12)");
  //   Parser parser(scanner);
  //   ASSERT_EQ("...(11, 12)", parser.createTerm()->symbol());
  // }

  // // Given there is string: "point(11)" in scanner.
  // // When parser parses all terms via scanner.
  // // Then it should return a Struct.
  // // And #symbol() of Strcut should return "point(11)".
  // TEST_F(ParserTest, parseStructOneArg)
  // {
  //   Scanner scanner("point(11)");
  //   Parser parser(scanner);
  //   ASSERT_EQ("point(11)", parser.createTerm()->symbol());
  // }

#endif