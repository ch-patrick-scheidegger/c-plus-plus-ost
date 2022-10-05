#[===[ LIBRARY ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}ex03_countingToLower"
    "lib/CountingToLower.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}ex03_countingToLower" PUBLIC "lib")

#[===[ APPLICATION ]===]
add_executable("${CPL_TARGET_WEEK_PREFIX}ex03_countingToLower_app"
    "app/CountingToLowerApp.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex03_countingToLower_app" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex03_countingToLower"
)


#[===[ TESTS ]===]
add_executable("${CPL_TARGET_WEEK_PREFIX}ex03_countingToLower_tests"
    "tests/CountingToLowerTests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex03_countingToLower_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex03_countingToLower"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}ex03_countingToLower_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}ex03_countingToLower_tests")