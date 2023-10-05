#[===[ LIBRARY ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}sol02_counting"
    "lib/Counting.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}sol02_counting" PUBLIC "lib")


#[===[ APPLICATION ]===]

add_executable("${CPL_TARGET_WEEK_PREFIX}sol02a_charc_algorithm"
"apps/Charc.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol02a_charc_algorithm" PRIVATE
"${CPL_TARGET_WEEK_PREFIX}sol02_counting"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}sol02b_allcharc_algorithm"
    "apps/Allcharc.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol02b_allcharc_algorithm" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol02_counting"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}sol02c_wc_algorithm"
    "apps/Wc.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol02c_wc_algorithm" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol02_counting"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}sol02d_lc_algorithm"
    "apps/Lc.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol02d_lc_algorithm" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol02_counting"
)



#[===[ TESTS ]===]


add_executable("${CPL_TARGET_WEEK_PREFIX}sol02_counting_tests"
    "tests/CountingTests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol02_counting_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol02_counting"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}sol02_counting_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}sol02_counting_tests")