#[===[ LIBRARY ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}sol02_toggle_button_lib"
    "lib/Switch.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}sol02_toggle_button_lib" PUBLIC "lib")



#[===[ TESTS ]===]


add_executable("${CPL_TARGET_WEEK_PREFIX}sol02_toggle_button_tests"
    "tests/ToggleButtonTests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol02_toggle_button_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol02_toggle_button_lib"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}sol02_toggle_button_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}sol02_toggle_button_tests")