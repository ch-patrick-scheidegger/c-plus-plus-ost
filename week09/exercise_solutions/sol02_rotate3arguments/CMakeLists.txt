add_library("${CPL_TARGET_WEEK_PREFIX}sol02_rotate3arguments" INTERFACE)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}sol02_rotate3arguments" INTERFACE
    "lib"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}sol02_rotate3arguments_tests"
    "tests/Tests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol02_rotate3arguments_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol02_rotate3arguments"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}sol02_rotate3arguments_tests"
    COMMAND "${CPL_TARGET_WEEK_PREFIX}sol02_rotate3arguments_tests"
)
