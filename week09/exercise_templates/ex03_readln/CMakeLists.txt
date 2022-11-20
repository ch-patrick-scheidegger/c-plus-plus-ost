add_library("${CPL_TARGET_WEEK_PREFIX}ex03_readln" INTERFACE)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}ex03_readln" INTERFACE
    "lib"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}ex03_readln_tests"
    "tests/Tests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex03_readln_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex03_readln"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}ex03_readln_tests"
    COMMAND "${CPL_TARGET_WEEK_PREFIX}ex03_readln_tests"
)
