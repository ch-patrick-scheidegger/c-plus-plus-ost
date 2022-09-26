#[===[ LIBRARY ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}sol03_counting"
    "lib/Counting.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}sol03_counting" PUBLIC "lib")


#[===[ APPLICATION ]===]

add_executable("${CPL_TARGET_WEEK_PREFIX}sol03a_charc_loop"
"apps/Charc.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol03a_charc_loop" PRIVATE
"${CPL_TARGET_WEEK_PREFIX}sol03_counting"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}sol03b_allcharc_loop"
    "apps/Charc.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol03b_allcharc_loop" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol03_counting"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}sol03c_wc_loop"
    "apps/Charc.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol03c_wc_loop" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol03_counting"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}sol03d_lc_loop"
    "apps/Charc.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol03d_lc_loop" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol03_counting"
)



#[===[ TESTS ]===]


add_executable("${CPL_TARGET_WEEK_PREFIX}sol03_tests"
    "tests/CountingTests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol03_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol03_counting"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}sol03_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}sol03_tests")