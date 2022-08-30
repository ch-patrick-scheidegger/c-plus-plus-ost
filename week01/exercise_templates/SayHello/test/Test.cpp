#include "sayHello.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/xml_listener.h>

#include <sstream>

TEST(testSayHelloWritesHelloWorldWithNewlineToTheOutputStream) {
  auto output = std::ostringstream{};
  sayHello(output);
  ASSERT_EQUAL("Hello, world!\n", output.str());
}

auto runSuite(cute::runner<cute::xml_listener<cute::ide_listener<>>> runner) -> bool {
  cute::suite s{};

  s += testSayHelloWritesHelloWorldWithNewlineToTheOutputStream();

  return runner(s, "TestSuite");
}

auto main(int argc, char const *argv[]) -> int {
  cute::xml_file_opener xmlfile(argc, argv);
  cute::xml_listener<cute::ide_listener<>> listener(xmlfile.out);
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runSuite(runner);
  
  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}