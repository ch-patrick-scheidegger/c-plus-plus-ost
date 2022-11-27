#include "sack.hpp"

#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

TEST(test_can_instantiate_with_char_pointer) {
  Sack<char> scrabble{};
  // Sack<int*> shouldntcompile{};
  Sack<char const *> sackforstringliterals{};
  ASSERTM("only compilation tested", true);
}

TEST(test_make_Sack_with_int) {
  auto sack = makeSack({1, 2, 3, 4, 5, 6});
  ASSERT_EQUAL(6, sack.size());
}

TEST(test_CTAD_for_Sack) {
  auto sack = Sack{1.0f, 2.0f, 3.0f};
  ASSERT(!sack.empty());
}

TEST(test_make_sack_with_c_strings) {
  auto sack = makeSack({"Hello", ",", "World", "!"});
  ASSERT_EQUAL(4, sack.size());
  ASSERT_EQUAL("!", sack.getOut());
  ASSERT_EQUAL("Hello", sack.getOut());
  ASSERT_EQUAL("World", sack.getOut());
  ASSERT_EQUAL(",", sack.getOut());
  ASSERT_THROWS(sack.getOut(), std::logic_error);
}

auto main(int argc, char const *argv[]) -> int {
  auto suite = cute::suite{
    "Sack<T> Tests",
    {
      test_can_instantiate_with_char_pointer,
      test_CTAD_for_Sack,
      test_make_Sack_with_int,
      test_make_sack_with_c_strings,
    }
  };

  auto listener = cute::ide_listener<cute::summary_listener<>>{};
  auto runner = cute::makeRunner(listener, argc, argv);

  return runner(suite) ? EXIT_SUCCESS : EXIT_FAILURE;
}
