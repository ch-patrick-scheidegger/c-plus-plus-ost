
#include "Switch.hpp"

#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>
#include <sstream>


TEST(testOutputOfSwitch) {
	// Switch s{};
	// std::ostringstream out{};
	// out << s << '\n';
	// s.pressButton();
	// out << s << '\n';
	// s.pressButton();
	// out << s << '\n';
	// s.pressButton();
	// out << s << '\n';
	// s.pressButton();
	// out << s << '\n';
	// ASSERT_EQUAL(
	// 		"off\n"
	// 		"on\n"
	// 		"blinking\n"
	// 		"off\n"
	// 		"on\n", out.str());
}

auto testToggleSuite() -> cute::suite {
  return cute::suite {
    "Toggle Suite",
	{
		testOutputOfSwitch,
    }
  };
}

auto main(int argc, char const* argv[]) -> int {
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runner(testToggleSuite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}