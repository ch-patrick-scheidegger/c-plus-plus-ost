#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "Switch.h"

#include <sstream>


void testOutputOfSwitch() {
	Switch s{};
	std::ostringstream out{};
	out << s << '\n';
	s.pressButton();
	out << s << '\n';
	s.pressButton();
	out << s << '\n';
	s.pressButton();
	out << s << '\n';
	s.pressButton();
	out << s << '\n';
	ASSERT_EQUAL(
			"off\n"
			"on\n"
			"blinking\n"
			"off\n"
			"on\n", out.str());
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(testOutputOfSwitch));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
