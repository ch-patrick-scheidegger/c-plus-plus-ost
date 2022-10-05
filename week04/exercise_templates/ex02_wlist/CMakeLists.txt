#[===[ LIBRARY ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}ex02_wlist"
    "lib/Wlist.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}ex02_wlist" PUBLIC "lib")

#[===[ APPLICATION ]===]
add_executable("${CPL_TARGET_WEEK_PREFIX}ex02a_wlist_app"
    "apps/WlistApp.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex02a_wlist_app" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex02_wlist"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}ex02b_wlist_caseless_app"
    "apps/WlistCaselessApp.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex02b_wlist_caseless_app" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex02_wlist"
)

#[===[ TESTS ]===]
add_executable("${CPL_TARGET_WEEK_PREFIX}ex02_wlist_tests"
    "tests/WlistTests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex02_wlist_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex02_wlist"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}ex02_wlist_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}ex02_wlist_tests")