#include "meal.h"

#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <sstream>

void testFailingExample() {
	std::istringstream input{
		"Roger breakfast lunch\n"
		"John lunch dinner\n"
		"Peter dinner\n"
	};
	std::ostringstream output{};
	count_meals(input, output);
	ASSERT_EQUAL("Total: 3 breakfast: 1 lunch: 2 dinner: 2\n", output.str());
}

void testAllHaveFullBoard() {
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

void testAllHaveBreakfast() {
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

void testAllHaveLunch() {
	std::istringstream input{
		"Roger lunch\n"
		"Mary lunch\n"
		"Anna lunch\n"
		"Claire lunch\n"
		"John lunch\n"
	};
	std::ostringstream output{};
	count_meals(input, output);
	ASSERT_EQUAL("Total: 5 breakfast: 0 lunch: 5 dinner: 0\n", output.str());
}

void testAllHaveDinner() {
	std::istringstream input{
		"Roger dinner\n"
		"Mary dinner\n"
		"Anna dinner\n"
		"Claire dinner\n"
		"John dinner\n"
	};
	std::ostringstream output{};
	count_meals(input, output);
	ASSERT_EQUAL("Total: 5 breakfast: 0 lunch: 0 dinner: 5\n", output.str());
}


void testEmptyInput() {
	std::istringstream input{};
	std::ostringstream output{};
	count_meals(input, output);
	ASSERT_EQUAL("Total: 0 breakfast: 0 lunch: 0 dinner: 0\n", output.str());
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(testFailingExample));
	s.push_back(CUTE(testEmptyInput));
	s.push_back(CUTE(testAllHaveFullBoard));
	s.push_back(CUTE(testAllHaveBreakfast));
	s.push_back(CUTE(testAllHaveLunch));
	s.push_back(CUTE(testAllHaveDinner));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
