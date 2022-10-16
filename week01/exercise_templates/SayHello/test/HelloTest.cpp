#include "Hello.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>

#include <sstream>

TEST(testSayHelloWritesHelloWorldWithNewlineToTheOutputStream) {
  auto output = std::ostringstream{};
  sayHello(output);
  ASSERT_EQUAL("Hello World!\n", output.str());
}

auto createCharcSuite() -> cute::suite {
  cute::suite helloSuite{};

  helloSuite += testSayHelloWritesHelloWorldWithNewlineToTheOutputStream;

  return helloSuite;
}

auto main(int argc, char const* argv[]) -> int {
  cute::ide_listener<> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  auto helloSuite = createCharcSuite();

  bool suiteResult = runner(helloSuite, "Hello Suite");

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}