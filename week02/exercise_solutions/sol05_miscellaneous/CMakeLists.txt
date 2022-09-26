#[===[ LIBRARY ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}sol05_miscellaneous_lib"
    "lib/Average.cpp"
    "lib/Sum.cpp"
    "lib/Tables.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}sol05_miscellaneous_lib" PUBLIC "lib")


#[===[ APPLICATION ]===]

add_executable("${CPL_TARGET_WEEK_PREFIX}sol05a_sumi"
"apps/SumiApp.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol05a_sumi" PRIVATE
"${CPL_TARGET_WEEK_PREFIX}sol05_miscellaneous_lib"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}sol05a_sumf"
    "apps/SumfApp.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol05a_sumf" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol05_miscellaneous_lib"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}sol05b_averagei"
    "apps/AverageiApp.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol05b_averagei" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol05_miscellaneous_lib"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}sol05b_averagef"
    "apps/AveragefApp.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol05b_averagef" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol05_miscellaneous_lib"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}sol05c_multab"
    "apps/MultabApp.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol05c_multab" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol05_miscellaneous_lib"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}sol05d_fractab"
    "apps/MultabApp.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol05d_fractab" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol05_miscellaneous_lib"
)



#[===[ TESTS ]===]


add_executable("${CPL_TARGET_WEEK_PREFIX}sol05a_sum_tests"
    "tests/SumTests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol05a_sum_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol05_miscellaneous_lib"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}sol05a_sum_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}sol05a_sum_tests")


add_executable("${CPL_TARGET_WEEK_PREFIX}sol05b_average_tests"
    "tests/AverageTests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol05b_average_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol05_miscellaneous_lib"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}sol05b_average_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}sol05b_average_tests")


add_executable("${CPL_TARGET_WEEK_PREFIX}sol05c_multab_tests"
    "tests/MultabTests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol05c_multab_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol05_miscellaneous_lib"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}sol05c_multab_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}sol05c_multab_tests")


add_executable("${CPL_TARGET_WEEK_PREFIX}sol05d_fractab_tests"
    "tests/FractabTests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol05d_fractab_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol05_miscellaneous_lib"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}sol05d_fractab_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}sol05d_fractab_tests")
