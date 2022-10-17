#[===[ LIBRARY ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}ex01_word_lib"
    "lib/Word.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}ex01_word_lib" PUBLIC "lib")



#[===[ TESTS ]===]


add_executable("${CPL_TARGET_WEEK_PREFIX}ex01_word_tests"
    "tests/WordTests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex01_word_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex01_word_lib"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}ex01_word_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}ex01_word_tests")
