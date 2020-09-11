#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "lc.h"
#include <sstream>

void testLcOnEmptyIstream() {
	std::istringstream input{};
	ASSERT_EQUAL(0u, lc(input));
}

void testLcOnSingleLineIstream() {
	std::istringstream input{"single line"};
	ASSERT_EQUAL(1u, lc(input));
}

void testLcOnMultiLineIstream() {
	std::istringstream input{"multi \n line\n  \n stream"};
	ASSERT_EQUAL(4u, lc(input));
}

void testLcOnWhitespaceOnlyIstream() {
	std::istringstream input{"   \n\n\t\t   "};
	ASSERT_EQUAL(3u, lc(input));
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s{};
	s.push_back(CUTE(testLcOnEmptyIstream));
	s.push_back(CUTE(testLcOnSingleLineIstream));
	s.push_back(CUTE(testLcOnMultiLineIstream));
	s.push_back(CUTE(testLcOnWhitespaceOnlyIstream));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
