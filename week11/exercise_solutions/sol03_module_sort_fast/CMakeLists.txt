#[====[ Library ]====]

add_library("${CPL_TARGET_WEEK_PREFIX}sol03_module_sort_fast_lib"
    "lib/module.cpp"
    "lib/semester.cpp"
    "lib/semesterSort.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}sol03_module_sort_fast_lib" PUBLIC
    "lib"
)

#[====[ Application ]====]

add_executable("${CPL_TARGET_WEEK_PREFIX}sol03_module_sort_fast"
    "app/main.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol03_module_sort_fast" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol03_module_sort_fast_lib"
)
