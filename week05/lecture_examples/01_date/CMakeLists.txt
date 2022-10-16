#[===[ LIBRARY ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}01_date_lib"
    "lib/Date.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}01_date_lib" PUBLIC "lib")



#[===[ TESTS ]===]


add_executable("${CPL_TARGET_WEEK_PREFIX}01_date_tests"
    "tests/DateTests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}01_date_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}01_date_lib"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}01_date_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}01_date_tests")