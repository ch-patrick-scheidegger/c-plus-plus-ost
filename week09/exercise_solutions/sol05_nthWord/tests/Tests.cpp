#include "nthWord.hpp"

#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <fstream>
#include <sstream>

TEST(test_seventh_with_empty_input) {
  std::istringstream in{};
  std::ostringstream out{};

  nth(in, out, 7);

  ASSERT_EQUAL("Not enough words in input!\n", out.str());
}

TEST(test_seventh_with_six_input_words) {
  std::istringstream in{"A B C D E F A B C D E F A A"};
  std::ostringstream out{};

  nth(in, out, 9);

  ASSERT_EQUAL("Not enough words in input!\n", out.str());
}

TEST(test_seventh_with_seven_input_words) {
  std::istringstream in{"A B C D E F A B G C D E F F F"};
  std::ostringstream out{};

  nth(in, out, 7);

  ASSERT_EQUAL("G\n", out.str());
}

TEST(test_seventh_with_lorem_ipsum) {
  std::ifstream in{"lorem_ipsum.txt"};
  std::ostringstream out{};

  nth(in, out, 7);

  ASSERT_EQUAL("felis\n", out.str());
}

TEST(test_seventh_with_chapter_six) {
  std::ifstream in{"chapter_6.txt"};
  std::ostringstream out{};

  nth(in, out, 7);

  ASSERT_EQUAL("is\n", out.str());
}

auto main(int argc, char const *argv[]) -> int {
  auto suite = cute::suite{
    "'nthWord' Tests",
    {
      test_seventh_with_empty_input,
      test_seventh_with_six_input_words,
      test_seventh_with_seven_input_words,
      test_seventh_with_lorem_ipsum,
      test_seventh_with_chapter_six,
    }
  };

  auto listener = cute::ide_listener<cute::summary_listener<>>{};
  auto runner = cute::makeRunner(listener, argc, argv);

  return runner(suite) ? EXIT_SUCCESS : EXIT_FAILURE;
}
