#[====[ Library ]====]

add_library("${CPL_TARGET_WEEK_PREFIX}day1_lib" INTERFACE)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}day1_lib" INTERFACE
    "lib"
)

#[====[ Application ]====]

add_executable("${CPL_TARGET_WEEK_PREFIX}day1"
    "app/main.cpp"
        lib/MapNumberReader.cpp
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}day1" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}day1_lib"
)

#[====[ Application ]====]

#add_executable("${CPL_TARGET_WEEK_PREFIX}day1_tests"
#    "tests/main.cpp"
#)
#
#target_link_libraries("${CPL_TARGET_WEEK_PREFIX}day1_tests" PRIVATE
#    "${CPL_TARGET_WEEK_PREFIX}day1_lib"
#    "cpl::cute"
#)
#
#add_test(NAME "${CPL_TARGET_WEEK_PREFIX}day1_tests"
#    COMMAND "${CPL_TARGET_WEEK_PREFIX}day1_tests"
#)
