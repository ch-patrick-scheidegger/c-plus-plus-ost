#[====[ Library ]====]

add_library("${CPL_TARGET_WEEK_PREFIX}ex01_indexable_set" INTERFACE)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}ex01_indexable_set" INTERFACE
    "lib"
)

#[====[ Tests ]====]

add_executable("${CPL_TARGET_WEEK_PREFIX}ex01_indexable_set_tests"
    "tests/main.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex01_indexable_set_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex01_indexable_set"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}ex01_indexable_set_tests"
    COMMAND "${CPL_TARGET_WEEK_PREFIX}ex01_indexable_set_tests"
)
