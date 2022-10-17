#include "Word.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>

//TODO: Add more tests

TEST(test_cannot_create_empty_word) {
  // ASSERT_THROWS(Word{""}, std::invalid_argument);
}

TEST(test_cannot_create_word_with_space) {
  // ASSERT_THROWS(Word{"abc xyz"}, std::invalid_argument);
}

TEST(test_cannot_create_word_with_number) {
  // ASSERT_THROWS(Word{"abc3xyz"}, std::invalid_argument);
}

TEST(test_cannot_create_word_with_punctuation) {
  // ASSERT_THROWS(Word{"abc.xyz"}, std::invalid_argument);
}

TEST(test_output_operator) {
  // std::string const expected{"Python"};
  // Word const w{expected};
  // std::ostringstream output{};
  // output << w;
  // ASSERT_EQUAL(expected, output.str());
}

TEST(test_same_words_are_equal) { 
  // ASSERT_EQUAL(Word{"Ruby"}, Word{"Ruby"}); 
}

TEST(test_different_words_are_not_equal) {
  // ASSERT_NOT_EQUAL_TO(Word{"Haskell"}, Word{"ML"});
}

TEST(test_same_word_with_different_cases_are_equal) {
  // ASSERT_EQUAL(Word{"BASIC"}, Word{"basic"});
}

TEST(test_same_word_is_not_lower_than) {
  // ASSERT(!(Word{"Erlang"} < Word{"Erlang"}));
}

TEST(test_smaller_word_is_smaller) {
  // ASSERT_LESS(Word{"Erlang"}, Word{"Fortran"});
}

TEST(test_smaller_word_with_capital_letters_is_smaller) {
  // ASSERT_LESS(Word{"ADA"}, Word{"java"});
}

TEST(test_same_word_with_different_cases_are_not_smaller) {
  // ASSERT(!(Word{"Groovy"} < Word{"groovy"}));
}

TEST(test_greater_word_is_greater) {
  // ASSERT_GREATER(Word{"Rust"}, Word{"Prolog"});
}

TEST(test_greater_word_with_capital_letters_is_greater) {
  // ASSERT_GREATER(Word{"Lisp"}, Word{"brainfuck"});
}

TEST(test_smaller_word_is_less_equal) {
  // ASSERT_LESS_EQUAL(Word{"Algol"}, Word{"BCPL"});
}

TEST(test_same_word_is_less_equal) {
  // ASSERT_LESS_EQUAL(Word{"Assembler"}, Word{"Assembler"});
}

TEST(test_greater_word_is_greater_equal) {
  // ASSERT_GREATER_EQUAL(Word{"RPG"}, Word{"Perl"});
}

TEST(test_same_word_is_greater_equal) {
  // ASSERT_GREATER_EQUAL(Word{"Scala"}, Word{"Scala"});
}

TEST(test_input_operator_single_word) {
  // std::istringstream input{"Elixir"};
  // Word w{};
  // input >> w;
  // ASSERT_EQUAL(Word{"Elixir"}, w);
}

TEST(test_input_operator_single_word_stream_good) {
  // std::istringstream input{"Cobol"};
  // Word w{};
  // ASSERT(input >> w);
}

TEST(test_input_operator_called_once_first_word) {
  // std::istringstream input{"Ceylon Go"};
  // Word w{};
  // input >> w;
  // ASSERT_EQUAL(Word{"Ceylon"}, w);
}

TEST(test_input_operator_called_once_stream_good) {
  // std::istringstream input{"Lua Oberon"};
  // Word w{};
  // ASSERT(input >> w);
}

TEST(test_input_operator_on_empty_stream_fail) {
  // std::istringstream input{};
  // Word w{};
  // input >> w;
  // ASSERT(input.fail());
}

TEST(test_input_operator_on_stream_without_word) {
  // std::istringstream input{"1337"};
  // Word w{};
  // input >> w;
  // ASSERT(input.fail());
}

TEST(test_input_operator_on_empty_stream_word_unchanged) {
  // std::istringstream input{};
  // Word w{"Eiffel"};
  // input >> w;
  // ASSERT_EQUAL(Word{"Eiffel"}, w);
}

TEST(test_input_operator_stops_on_slash) {
  // std::istringstream input{"PL/SQL"};
  // Word w{};
  // input >> w;
  // ASSERT_EQUAL(Word{"PL"}, w);
}

TEST(test_input_operator_stops_at_end_of_word) {
  // std::istringstream input{"VB6"};
  // Word w{};
  // int i{};
  // input >> w >> i;
  // ASSERT_EQUAL(6, i);
}

TEST(test_input_operator_skips_leading_non_alpha) {
  // std::istringstream input{"3switchBF"};
  // Word w{};
  // input >> w;
  // ASSERT_EQUAL(Word{"switchBF"}, w);
}

TEST(test_input_operator_overwrites_word) {
  // std::istringstream input{"Kotlin"};
  // Word w{"JavaScript"};
  // input >> w;
  // ASSERT_EQUAL(Word{"Kotlin"}, w);
}

TEST(test_exercise_example) {
  // std::istringstream input{"compl33tely ~ weird !!?!! 4matted in_put"};
  // Word w{};
  // input >> w;
  // ASSERT_EQUAL(Word{"compl"}, w);
  // input >> w;
  // ASSERT_EQUAL(Word{"tely"}, w);
  // input >> w;
  // ASSERT_EQUAL(Word{"weird"}, w);
  // input >> w;
  // ASSERT_EQUAL(Word{"matted"}, w);
  // input >> w;
  // ASSERT_EQUAL(Word{"in"}, w);
  // input >> w;
  // ASSERT_EQUAL(Word{"put"}, w);
  // input >> w;
  // ASSERT_EQUAL(Word{"put"}, w);
}



auto createWordSuite() -> cute::suite {
  cute::suite wordSuite{
    "Word Suite",
    {
  test_cannot_create_empty_word,
  test_cannot_create_word_with_space,
  test_cannot_create_word_with_number,
  test_cannot_create_word_with_punctuation,
  test_output_operator,
  test_same_words_are_equal,
  test_different_words_are_not_equal,
  test_same_word_with_different_cases_are_equal,
  test_same_word_is_not_lower_than,
  test_smaller_word_is_smaller,
  test_smaller_word_with_capital_letters_is_smaller,
  test_same_word_with_different_cases_are_not_smaller,
  test_greater_word_is_greater,
  test_greater_word_with_capital_letters_is_greater,
  test_smaller_word_is_less_equal,
  test_same_word_is_less_equal,
  test_greater_word_is_greater_equal,
  test_same_word_is_greater_equal,
  test_input_operator_single_word,
  test_input_operator_single_word_stream_good,
  test_input_operator_called_once_first_word,
  test_input_operator_called_once_stream_good,
  test_input_operator_on_empty_stream_fail,
  test_input_operator_on_stream_without_word,
  test_input_operator_on_empty_stream_word_unchanged,
  test_input_operator_stops_on_slash,
  test_input_operator_stops_at_end_of_word,
  test_input_operator_skips_leading_non_alpha,
  test_input_operator_overwrites_word,
  test_exercise_example,
    }
  };
  return wordSuite;
}

auto main(int argc, char const* argv[]) -> int {
    
  cute::ide_listener<cute::summary_listener<>> listener{};
  auto runner = cute::makeRunner(listener, argc, argv);

  bool suiteResult = runner(createWordSuite());

  return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}