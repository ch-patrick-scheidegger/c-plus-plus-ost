#[===[ Library ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}ex04_wcount_lib"
    "lib/wcount.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}ex04_wcount_lib" PUBLIC
    "lib"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex04_wcount_lib" PUBLIC
    "w05_ex01_word_lib"
)

#[===[ App ]===]

add_executable("${CPL_TARGET_WEEK_PREFIX}ex04_wcount_app"
    "app/main.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex04_wcount_app" PUBLIC
    "${CPL_TARGET_WEEK_PREFIX}ex04_wcount_lib"
)

#[===[ Tests ]===]

add_executable("${CPL_TARGET_WEEK_PREFIX}ex04_wcount_tests"
    "tests/Tests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex04_wcount_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex04_wcount_lib"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}ex04_wcount_tests"
    COMMAND "${CPL_TARGET_WEEK_PREFIX}ex04_wcount_tests"
)
