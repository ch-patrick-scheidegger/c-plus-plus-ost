add_library("${CPL_TARGET_WEEK_PREFIX}sol01_median" INTERFACE)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}sol01_median" INTERFACE
    "lib"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}sol01_median_tests"
    "tests/Tests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol01_median_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol01_median"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}sol01_median_tests"
    COMMAND "${CPL_TARGET_WEEK_PREFIX}sol01_median_tests"
)
