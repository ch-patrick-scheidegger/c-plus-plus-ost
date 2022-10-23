#[===[ LIBRARY ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}ex03_field5_lib"
    "lib/Field5.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}ex03_field5_lib" PUBLIC "lib")

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex03_field5_lib" PUBLIC "cpl::boost")


#[===[ TESTS ]===]


add_executable("${CPL_TARGET_WEEK_PREFIX}ex03_field5_tests"
    "tests/Field5Tests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex03_field5_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex03_field5_lib"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}ex03_field5_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}ex03_field5_tests")