#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/xml_listener.h>

#include "HelloFunction.hpp"

#include <sstream>

TEST(testSayHelloSaysHelloWorld) {
  std::ostringstream out{};
  sayHello(out);
  ASSERT_EQUAL("Hello, world!\n", out.str());
}

auto runAllTests(int argc, char const *argv[]) -> void {
  cute::suite s;

  s.push_back(testSayHelloSaysHelloWorld);

  cute::xml_file_opener xmlfile(argc, argv);
  cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
  cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

auto main(int argc, char const *argv[]) -> int {
  runAllTests(argc, argv);
  return 0;
}
