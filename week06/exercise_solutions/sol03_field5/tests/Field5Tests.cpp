#include "Field5.hpp"

#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <cstdlib>
#include <sstream>

TEST(testDefaultCtor) {
	Field5 v { };
	ASSERT_EQUAL(0, v.value());
}

TEST(testValueCtor) {
	Field5 four { 4 };
	ASSERT_EQUAL(4, four.value());
}

// operator==, operator<< for failures
TEST(testValueCtorWithLargeInput) {
	Field5 four { 19 };
	ASSERT_EQUAL(Field5 { 4 }, four);
}

// define operator<< format
TEST(testOutputOperator) {
	std::ostringstream out;
	out << Field5 { 4 };
	ASSERT_EQUAL("Field5{4}", out.str());
}

TEST(testAddition) {
	Field5 const two { 2 };
	Field5 const four = two + two;
	ASSERT_EQUAL(4, four.value());
}

TEST(testAdditionWrap) {
	Field5 four { 4 };
	Field5 three = four + four;
	ASSERT_EQUAL(3, three.value());
}

TEST(testMultiplication) {
	Field5 four { 4 };
	Field5 three { 3 };
	Field5 two = four * three;
	ASSERT_EQUAL(Field5 { 2 }, two);
}

TEST(testAdditionWithInt) {
	Field5 two { 2 };
	auto four = two + Field5 { 2 };
	ASSERT_EQUAL(Field5 { 4 }, four);
	ASSERT_EQUAL(typeid(Field5).name(), typeid(decltype(four)).name());
}

TEST(testAssignmentBackToInt) {
	Field5 three { 8 };
	unsigned u3 = three;
	unsigned eight = three + 5u;
	ASSERT_EQUAL(8u, eight);
	ASSERT_EQUAL(3u, three);
	ASSERT_EQUAL(3u, u3);
}

TEST(testAdditionWithIntExplicitCtor) {
	Field5 two { 2 };
	auto four = two + Field5 { 2u };
	ASSERT_EQUAL(Field5 { 4 }, four);
	ASSERT_EQUAL(typeid(Field5).name(), typeid(decltype(four)).name());
}

TEST(testAssignmentBackToIntExplicitCtor) {
	Field5 three { 8 };
	unsigned u3 = three;
	auto eight = three + 5u;
	ASSERT_EQUAL(8u, eight);
	ASSERT_EQUAL(3u, u3);
	ASSERT_EQUAL(3u, three);
}

TEST(testSubtract) {
	Field5 four { 4 };
	Field5 one { 1 };
	ASSERT_EQUAL(Field5 { 3 }, four - one);
	ASSERT_EQUAL(Field5 { 2 }, one - four);
}

TEST(testDivision) {
	Field5 four { 4 };
	ASSERT_EQUAL(Field5 { 1 }, four / four);
	ASSERT_EQUAL(Field5 { 2 }, four / Field5 { 2 });
	ASSERT_EQUAL(Field5 { 3 }, four / Field5 { 3 });
	ASSERT_EQUAL(four, four / Field5 { 1 });
	ASSERT_EQUAL(four, Field5 { 2 } / Field5 { 3 });
	ASSERT_EQUAL(four, Field5 { 3 } / Field5 { 2 });
}

auto createField5Suite() -> cute::suite {
	return cute::suite{
		"Field5 Suite",
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
			testAssignmentBackToIntExplicitCtor,
			testSubtract,
			testDivision,
		}
	};
}

auto main(int argc, char const* argv[]) -> int {
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runner(createField5Suite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}
