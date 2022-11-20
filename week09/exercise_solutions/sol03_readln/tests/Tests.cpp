#include "readln.hpp"

#include <cute/cute_runner.h>
#include <cute/cute.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>
#include <string>

TEST(testEmptyreadln) {
  std::istringstream in{""};
  int var{};
  readln(in, var);
  ASSERT(in.fail());
}

TEST(testFailedreadln) {
  std::istringstream in{"a\n"};
  int var{};
  readln(in, var);
  ASSERT(in.fail());
}

TEST(testSuccessfulreadlnwithoutlineend) {
  std::istringstream in{"42"};
  int var{};
  readln(in, var);
  ASSERT_EQUAL(42, var);
  ASSERT(!in.fail());
}

TEST(testReadlnwithstringconsumestoeol) {
  std::istringstream in{"1 some rest 123\n2the rest\n"};
  std::string rest{};
  int first{};
  readln(in, first, rest);
  ASSERT_EQUAL(1, first);
  ASSERT_EQUAL(" some rest 123", rest);
  readln(in, first, rest);
  ASSERT_EQUAL(2, first);
  ASSERT_EQUAL("the rest", rest);
}

TEST(testNonStringAtEnd) {
  std::istringstream in{"1 2 3\n"};
  int a{}, b{}, c{}, d{};
  readln(in, a, b, c, d);
  ASSERT_EQUAL(1, a);
  ASSERT_EQUAL(0, d);
}

TEST(testLongreadln) {
  std::istringstream in{"one 1 two \02 three 3.0\nthe rest\n"};
  std::string one{};
  std::string two{};
  std::string three{};
  int ione{};
  char ctwo{};
  double dthree{};

  readln(in, one, ione, two, ctwo, three, dthree);
  std::string rest;
  readln(in, rest);
  ASSERT_EQUAL("one", one);
  ASSERT_EQUAL("two", two);
  ASSERT_EQUAL("three", three);
  ASSERT_EQUAL(1, ione);
  ASSERT_EQUAL('\02', ctwo);
  ASSERT_EQUAL(3.0, dthree);
  ASSERT_EQUAL("the rest", rest);
}

auto main(int argc, char const *argv[]) -> int {
  auto suite = cute::suite{
    "Function Template 'readln' Tests",
    {
      testEmptyreadln,
      testFailedreadln,
      testSuccessfulreadlnwithoutlineend,
      testReadlnwithstringconsumestoeol,
      testNonStringAtEnd,
      testLongreadln,
    }
  };

  auto listener = cute::ide_listener<cute::summary_listener<>>{};
  auto runner = cute::makeRunner(listener, argc, argv);

  return runner(suite) ? EXIT_SUCCESS : EXIT_FAILURE;
}
