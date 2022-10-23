#[===[ LIBRARY ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}04_ring5_lib"
    "lib/Ring5.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}04_ring5_lib" PUBLIC "lib")



#[===[ TESTS ]===]


add_executable("${CPL_TARGET_WEEK_PREFIX}04_ring5_tests"
    "tests/Ring5Tests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}04_ring5_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}04_ring5_lib"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}04_ring5_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}04_ring5_tests")