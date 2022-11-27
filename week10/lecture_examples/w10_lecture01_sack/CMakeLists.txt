#[====[ Libraries ]====]

add_library("${CPL_TARGET_WEEK_PREFIX}lecture01_sack" INTERFACE)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}lecture01_sack" PUBLIC INTERFACE
    "lib"
)

#[====[ Tests ]====]

add_executable("${CPL_TARGET_WEEK_PREFIX}lecture01_sack_tests"
    "tests/main.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}lecture01_sack_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}lecture01_sack"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}lecture01_sack_tests"
    COMMAND "${CPL_TARGET_WEEK_PREFIX}lecture01_sack_tests"
)

#[====[ Applications ]====]

add_executable("${CPL_TARGET_WEEK_PREFIX}lecture01_sack_scrabble"
    "app/main.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}lecture01_sack_scrabble" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}lecture01_sack"
)

