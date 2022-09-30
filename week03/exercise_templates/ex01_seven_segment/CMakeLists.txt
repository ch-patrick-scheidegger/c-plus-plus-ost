#[===[ LIBRARY ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}ex01_seven_segment"
    "lib/Sevensegment.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}ex01_seven_segment" PUBLIC "lib")


#[===[ APPLICATION ]===]

add_executable("${CPL_TARGET_WEEK_PREFIX}ex01_seven_segment_app"
"app/SevensegmentApp.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex01_seven_segment_app" PRIVATE
"${CPL_TARGET_WEEK_PREFIX}ex01_seven_segment"
)


#[===[ TESTS ]===]


add_executable("${CPL_TARGET_WEEK_PREFIX}ex01_seven_segment_tests"
    "tests/SevensegmentTests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex01_seven_segment_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex01_seven_segment"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}ex01_seven_segment_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}ex01_seven_segment_tests")
