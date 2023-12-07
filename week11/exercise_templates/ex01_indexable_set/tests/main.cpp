#include "IndexableSet.hpp"

#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <iostream>

TEST(should_support_set_type_constructor) {
    // given .. when .. then
    IndexableSet<int> set {};
}

TEST(should_support_set_type_and_compare_function_constructor) {
    // given .. when .. then
    IndexableSet<int, std::greater<int>> set {};
}

TEST(should_return_first_result) {
    // given
    IndexableSet<int> set {0,1,2,3,4};
    // when
    auto result = set.front();
    // then
    ASSERT_EQUAL(0, result);
}

TEST(should_return_last_result) {
    // given
    IndexableSet<int> set {0,1,2,3,4};
    // when
    auto result = set.back();
    // then
    ASSERT_EQUAL(4, result);
}

TEST(should_return_correct_entry_when_using_positive_index_and_brackets) {
    // given
    std::array<int, 5> entries {0,1,2,3,4};
    IndexableSet<int> set {0,1,2,3,4};
    for(int i {0}; i < entries.size(); i++){
        // when
        auto result = set[i];
        // then
        ASSERT_EQUAL(entries[i], result);
    }
}

TEST(should_return_correct_entry_when_using_negative_index_and_brackets) {
    // given
    std::array<int, 5> entries {0,1,2,3,4};
    IndexableSet<int> set {0,1,2,3,4};
    for(int i {-1}; i >= -entries.size(); i--){
        // when
        auto result = set[i];
        // then
        ASSERT_EQUAL(entries[entries.size() + i], result);
    }
}

TEST(should_return_correct_entry_when_using_positive_index_and_at_method) {
    // given
    std::array<int, 5> entries {0,1,2,3,4};
    IndexableSet<int> set {0,1,2,3,4};
    for(int i {0}; i < entries.size(); i++){
        // when
        auto result = set.at(i);
        // then
        ASSERT_EQUAL(entries[i], result);
    }
}

TEST(should_return_correct_entry_when_using_negative_index_and_at_method) {
    // given
    std::array<int, 5> entries {0,1,2,3,4};
    IndexableSet<int> set {0,1,2,3,4};
    for(int i {-1}; i >= -entries.size(); i--){
        // when
        auto result = set.at(i);
        // then
        ASSERT_EQUAL(entries[entries.size() + i], result);
    }
}

auto main(int argc, char const *argv[]) -> int {
  auto suite = cute::suite{
    "IndexableSet<T> Tests",
    {
        should_support_set_type_constructor,
        should_support_set_type_and_compare_function_constructor,
        should_return_first_result,
        should_return_last_result,
        should_return_correct_entry_when_using_positive_index_and_brackets,
        should_return_correct_entry_when_using_negative_index_and_brackets,
        should_return_correct_entry_when_using_positive_index_and_at_method,
        should_return_correct_entry_when_using_negative_index_and_at_method,
    }
  };

  auto listener = cute::ide_listener<cute::summary_listener<>>{};
  auto runner = cute::makeRunner(listener, argc, argv);

  return runner(suite) ? EXIT_SUCCESS : EXIT_FAILURE;
}
