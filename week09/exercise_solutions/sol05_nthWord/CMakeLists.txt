#[===[ Library ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}sol05_nthWord_lib"
    "lib/nthWord.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}sol05_nthWord_lib" PUBLIC
    "lib"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol05_nthWord_lib" PUBLIC
    "w05_ex01_word_lib"
)

#[===[ Tests ]===]

add_executable("${CPL_TARGET_WEEK_PREFIX}sol05_nthWord_tests"
    "tests/Tests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol05_nthWord_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol05_nthWord_lib"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}sol05_nthWord_tests"
    COMMAND "${CPL_TARGET_WEEK_PREFIX}sol05_nthWord_tests"
)
