#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <cstdlib>

auto createCopyAndReplaceSuite() -> cute::suite;
auto createFillAndGenerateSuite() -> cute::suite;
auto createFindSuite() -> cute::suite;
auto createHeapSuite() -> cute::suite;
auto createMinMaxSuite() -> cute::suite;
auto createNumericSuite() -> cute::suite;
auto createPartitionSuite() -> cute::suite;
auto createPropertyCheckingSuite() -> cute::suite;
auto createRemoveUniqueRotateSuite() -> cute::suite;
auto createSetSuite() -> cute::suite;
auto createSortSuite() -> cute::suite;
auto createSortedSequenceSuite() -> cute::suite;

auto main(int argc, char const * * argv) -> int {
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runner(createCopyAndReplaceSuite());
  suiteResult &= runner(createFillAndGenerateSuite());
  suiteResult &= runner(createFindSuite());
  suiteResult &= runner(createHeapSuite());
  suiteResult &= runner(createMinMaxSuite());
  suiteResult &= runner(createNumericSuite());
  suiteResult &= runner(createPartitionSuite());
  suiteResult &= runner(createPropertyCheckingSuite());
  suiteResult &= runner(createRemoveUniqueRotateSuite());
  suiteResult &= runner(createSetSuite());
  suiteResult &= runner(createSortSuite());
  suiteResult &= runner(createSortedSequenceSuite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}
