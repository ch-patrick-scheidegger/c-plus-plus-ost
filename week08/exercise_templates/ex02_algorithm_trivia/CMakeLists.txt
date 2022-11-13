#[===[ TESTS ]===]

add_executable("${CPL_TARGET_WEEK_PREFIX}ex02_algorithm_trivia_tests"
    "tests/copy_and_replace_algorithms.cpp"
    "tests/fill_and_generate_algorithms.cpp"
    "tests/find_algorithms.cpp"
    "tests/heap_algorithms.cpp"
    "tests/min_max_algorithms.cpp"
    "tests/numeric_algorithms.cpp"
    "tests/partition_algorithms.cpp"
    "tests/property_checking_algorithms.cpp"
    "tests/remove_unique_rotate_algorithms.cpp"
    "tests/set_algorithms.cpp"
    "tests/sort_algorithms.cpp"
    "tests/sorted_sequence_algorithms.cpp"
    "tests/Test.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex02_algorithm_trivia_tests" PRIVATE
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}ex02_algorithm_trivia_tests"
    COMMAND "${CPL_TARGET_WEEK_PREFIX}ex02_algorithm_trivia_tests"
)