#[===[ LIBRARY ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}ex01_statistics_lib"
    "lib/Statistics.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}ex01_statistics_lib" PUBLIC "lib")

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex01_statistics_lib" PUBLIC "w05_ex01_word_lib")

#[===[ TESTS ]===]


add_executable("${CPL_TARGET_WEEK_PREFIX}ex01_statistics_tests"
    "tests/HistogramEntrySuite.cpp"
    "tests/PrintOccurrencesSuite.cpp"
    "tests/Test.cpp"
    "tests/TopSuite.cpp"
    "tests/WordHistogramSuite.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex01_statistics_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex01_statistics_lib"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}ex01_statistics_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}ex01_statistics_tests")
