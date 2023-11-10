#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>
#include <cute/xml_listener.h>

#include "HistogramEntrySuite.hpp"
#include "PrintOccurrencesSuite.hpp"
#include "TopSuite.hpp"
#include "WordHistogramSuite.hpp"

auto runAllTests(int argc, char const* argv[]) -> bool {
  cute::xml_file_opener xmlfile(argc, argv);
  cute::xml_listener<cute::ide_listener<cute::summary_listener<>>> lis(xmlfile.out);
  auto runner = cute::makeRunner(lis, argc, argv);
  bool success = true;
//  success &= runner(createHistogramEntrySuite());
  success &= runner(createTopSuite());
//  success &= runner(createPrintOccurrencesSuite());
//  success &= runner(createWordHistogramSuite());
  return success;
}

auto main(int argc, char const* argv[]) -> int {
  return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
