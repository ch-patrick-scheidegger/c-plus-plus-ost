#[===[ LIBRARY ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}ex03_counting"
    "lib/Counting.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}ex03_counting" PUBLIC "lib")


#[===[ APPLICATION ]===]

add_executable("${CPL_TARGET_WEEK_PREFIX}ex03a_charc_loop"
"apps/Charc.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex03a_charc_loop" PRIVATE
"${CPL_TARGET_WEEK_PREFIX}ex03_counting"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}ex03b_allcharc_loop"
    "apps/Charc.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex03b_allcharc_loop" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex03_counting"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}ex03c_wc_loop"
    "apps/Charc.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex03c_wc_loop" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex03_counting"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}ex03d_lc_loop"
    "apps/Charc.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex03d_lc_loop" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex03_counting"
)



#[===[ TESTS ]===]


add_executable("${CPL_TARGET_WEEK_PREFIX}ex03_tests"
    "tests/CountingTests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex03_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex03_counting"
    "cpl::cute"
)
