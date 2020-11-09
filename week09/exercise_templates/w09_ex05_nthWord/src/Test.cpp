#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <sstream>
#include "nthWord.h"

/*
 * Implement the nth() function that takes an std::istream and an std::ostream. It counts how
 * often every word occurs and prints the seventh most frequent word (beware: not the seven most frequent words).
 * Use your Word class from the previous exercises as it skips non-alphabet characters. You will need
 * to configure the dependency to your word class project (or copy the word files into this project)
 *
 * Add more tests below.
 *
 * This file contains two main() functions. One for running the tests, the other for running using
 * the nth() with the standard input.
 */



void test_seventh_with_empty_input() {
	std::istringstream in{};
	std::ostringstream out{};

	nth(in, out, 7);

	ASSERT_EQUAL("Not enough words in input!\n", out.str());
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	s.push_back(CUTE(test_seventh_with_empty_input));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner { cute::makeRunner(lis, argc, argv) };
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

//int main(int argc, char **argv) {
//	wseventh(std::cin, std::cout);
//}
