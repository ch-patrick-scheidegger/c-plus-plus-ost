#include "Kwic.hpp"

#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

TEST(should_return_correct_result_when_simple_input_is_given) {
    // given
    std::istringstream input{"A B C"};
    std::ostringstream out{};
    // when
    text::kwic(input, out);
    // then
    std::string expected{"A B C \nB C A \nC A B \n"};
    ASSERT_EQUAL(expected, out.str());
}

TEST(should_not_print_to_output_stream_when_no_valid_word_is_given) {
    // given
    std::istringstream input{"!.-+*ç%&/(1234567890"};
    std::ostringstream out{};
    // when
    text::kwic(input, out);
    // then
    std::string expected{""};
    ASSERT_EQUAL(expected, out.str());
}

TEST(should_not_print_to_output_stream_when_no_input_is_given) {
    // given
    std::istringstream input{""};
    std::ostringstream out{};
    // when
    text::kwic(input, out);
    // then
    std::string expected{""};
    ASSERT_EQUAL(expected, out.str());
}

TEST(should_print_single_word_when_only_one_is_given) {
    // given
    std::istringstream input{"a"};
    std::ostringstream out{};
    // when
    text::kwic(input, out);
    // then
    std::string expected{"a \n"};
    ASSERT_EQUAL(expected, out.str());
}

TEST(should_only_print_detected_words) {
    // given
    std::istringstream input{"a 1 2 3 4 5 6 7 8 9 b"};
    std::ostringstream out{};
    // when
    text::kwic(input, out);
    // then
    std::string expected{"a b \nb a \n"};
    ASSERT_EQUAL(expected, out.str());
}

auto createKwicSuite() -> cute::suite {
    cute::suite wordSuite{
        "Kwic Suite",
        {
            should_return_correct_result_when_simple_input_is_given,
            should_not_print_to_output_stream_when_no_valid_word_is_given,
            should_not_print_to_output_stream_when_no_input_is_given,
            should_print_single_word_when_only_one_is_given,
            should_only_print_detected_words,
        }
    };
    return wordSuite;
}

auto main(int argc, char const *argv[]) -> int {

    cute::ide_listener<cute::summary_listener<>> listener{};
    auto runner = cute::makeRunner(listener, argc, argv);

    bool suiteResult = runner(createKwicSuite());

    return suiteResult ? EXIT_SUCCESS : EXIT_FAILURE;
}