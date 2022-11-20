add_library("${CPL_TARGET_WEEK_PREFIX}ex02_rotate3Arguments" INTERFACE)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}ex02_rotate3Arguments" INTERFACE
    "lib"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}ex02_rotate3Arguments_tests"
    "tests/Tests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex02_rotate3Arguments_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex02_rotate3Arguments"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}ex02_rotate3Arguments_tests"
    COMMAND "${CPL_TARGET_WEEK_PREFIX}ex02_rotate3Arguments_tests"
)
