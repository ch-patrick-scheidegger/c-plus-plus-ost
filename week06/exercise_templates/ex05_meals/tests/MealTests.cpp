#include "Meal.hpp"

#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>
#include <sstream>

TEST(testFailingExample) {
	std::istringstream input{
		"Roger breakfast lunch\n"
		"John lunch dinner\n"
		"Peter dinner\n"
	};
	std::ostringstream output{};
	count_meals(input, output);
	// ASSERT_EQUAL("Total: 3 breakfast: 1 lunch: 2 dinner: 2\n", output.str());
}

TEST(testAllHaveFullBoard) {
	std::istringstream input{
		"Roger breakfast lunch dinner\n"
		"Mary breakfast lunch dinner\n"
		"Anna breakfast lunch dinner\n"
		"Claire breakfast lunch dinner\n"
		"John breakfast lunch dinner\n"
	};
	std::ostringstream output{};
	count_meals(input, output);
	ASSERT_EQUAL("Total: 5 breakfast: 5 lunch: 5 dinner: 5\n", output.str());
}

TEST(testAllHaveBreakfast) {
	std::istringstream input{
		"Roger breakfast\n"
		"Mary breakfast\n"
		"Anna breakfast\n"
		"Claire breakfast\n"
		"John breakfast\n"
	};
	std::ostringstream output{};
	count_meals(input, output);
	ASSERT_EQUAL("Total: 5 breakfast: 5 lunch: 0 dinner: 0\n", output.str());
}

TEST(testAllHaveLunch) {
	std::istringstream input{
		"Roger lunch\n"
		"Mary lunch\n"
		"Anna lunch\n"
		"Claire lunch\n"
		"John lunch\n"
	};
	std::ostringstream output{};
	count_meals(input, output);
	// ASSERT_EQUAL("Total: 5 breakfast: 0 lunch: 5 dinner: 0\n", output.str());
}

TEST(testAllHaveDinner) {
	std::istringstream input{
		"Roger dinner\n"
		"Mary dinner\n"
		"Anna dinner\n"
		"Claire dinner\n"
		"John dinner\n"
	};
	std::ostringstream output{};
	count_meals(input, output);
	// ASSERT_EQUAL("Total: 5 breakfast: 0 lunch: 0 dinner: 5\n", output.str());
}


TEST(testEmptyInput) {
	std::istringstream input{};
	std::ostringstream output{};
	count_meals(input, output);
	ASSERT_EQUAL("Total: 0 breakfast: 0 lunch: 0 dinner: 0\n", output.str());
}

auto createMealSuite() -> cute::suite {
	return cute::suite{
		"Meal Suite",
		{
			testFailingExample,
			testAllHaveFullBoard,
			testAllHaveBreakfast,
			testAllHaveLunch,
			testAllHaveDinner,
			testEmptyInput
		}
	};
}

auto main(int argc, char const* argv[]) -> int {
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runner(createMealSuite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}