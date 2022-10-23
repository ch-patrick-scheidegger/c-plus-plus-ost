#include "Ring5.hpp"

#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/cute_suite.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>
#include <cute/xml_listener.h>


TEST(testDefaultCtor) {
  Ring5 v{};
  ASSERT_EQUAL(0, v.value());
}

TEST(testValueCtor) {
  Ring5 four{4};
  ASSERT_EQUAL(4, four.value());
}

// operator==, operator<< for failures
TEST(testValueCtorWithLargeInput) {
  Ring5 four{19};
  ASSERT_EQUAL(Ring5{4}, four);
}

// define operator<< format
TEST(testOutputOperator) {
  std::ostringstream out;
  out << Ring5{4};
  ASSERT_EQUAL("Ring5{4}", out.str());
}

TEST(testAddition) {
  Ring5 two{2};
  Ring5 four = two + two;
  ASSERT_EQUAL(4, four.value());
}

TEST(testAdditionWrap) {
  Ring5 four{4};
  Ring5 three = four + four;
  ASSERT_EQUAL(3, three.value());
}

TEST(testMultiplication) {
  Ring5 four{4};
  Ring5 three{3};
  Ring5 two = four * three;
  ASSERT_EQUAL(Ring5{2}, two);
}

TEST(testAddAssignWithInteger) {
  Ring5 x{6};
  x += 8;
  ASSERT_EQUAL(Ring5{4}, x);
}

TEST(testAddWithInteger) {
  Ring5 x{6};
  x = x + 8;
  ASSERT_EQUAL(Ring5{4}, x);
  x = 8 + x;
  ASSERT_EQUAL(Ring5{2}, x);
}

TEST(testAdditionWithInt) {
  //*
  Ring5 two{2};
  auto four = two + 2u;
  ASSERT_EQUAL(Ring5{4}, four);
  ASSERT_EQUAL(typeid(Ring5).name(), typeid(decltype(four)).name());
  //*/
}

TEST(testAssignmentBackToInt) {
  Ring5 three{8};
  auto u3 = static_cast<unsigned>(three);
  //*
  unsigned eight(u3 + 5u);
  ASSERT_EQUAL(8u, eight);
  //*/
  ASSERT_EQUAL(Ring5{3}, three);
  ASSERT_EQUAL(3u, u3);
}

TEST(testAdditionWithIntExplicitCtor) {
  Ring5 two{2};
  auto four = two + Ring5{2u};
  ASSERT_EQUAL(Ring5{4}, four);
  ASSERT_EQUAL(typeid(Ring5).name(), typeid(decltype(four)).name());
}

auto createRing5Suite() -> cute::suite {
  return cute::suite{"Ring5 Suite",
                     {
                         testDefaultCtor,
                         testValueCtor,
                         testValueCtorWithLargeInput,
                         testAddition,
                         testAdditionWrap,
                         testOutputOperator,
                         testMultiplication,
                         testAdditionWithInt,
                         testAssignmentBackToInt,
                         testAdditionWithIntExplicitCtor,
                         testAddAssignWithInteger,
                         testAddWithInteger,
                     }};
}

auto main(int argc, char const* argv[]) -> int {
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runner(createRing5Suite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}