#[====[ Library ]====]

add_library("${CPL_TARGET_WEEK_PREFIX}ex03_module_sort_lib"
    "lib/module.cpp"
    "lib/moduleSort.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}ex03_module_sort_lib" PUBLIC
    "lib"
)

#[====[ Application ]====]

add_executable("${CPL_TARGET_WEEK_PREFIX}ex03_module_sort"
    "app/main.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex03_module_sort" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex03_module_sort_lib"
)

#[====[ Tests ]====]

add_executable("${CPL_TARGET_WEEK_PREFIX}ex03_module_sort_tests"
    "tests/main.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex03_module_sort_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex03_module_sort_lib"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}ex03_module_sort_tests"
    COMMAND "${CPL_TARGET_WEEK_PREFIX}ex03_module_sort_tests"
)
