#[====[ Library ]====]

add_library("${CPL_TARGET_WEEK_PREFIX}sol02_garden_plan_lib"
    "lib/bed.cpp"
    "lib/diamond.cpp"
    "lib/rectangle.cpp"
    "lib/shoppingList.cpp"
    "lib/square.cpp"
    "lib/triangle.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}sol02_garden_plan_lib" INTERFACE
    "lib"
)

#[====[ Application ]====]

add_executable("${CPL_TARGET_WEEK_PREFIX}sol02_garden_plan"
    "app/main.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol02_garden_plan" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol02_garden_plan_lib"
)

#[====[ Application ]====]

add_executable("${CPL_TARGET_WEEK_PREFIX}sol02_garden_plan_tests"
    "tests/main.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol02_garden_plan_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol02_garden_plan_lib"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}sol02_garden_plan_tests"
    COMMAND "${CPL_TARGET_WEEK_PREFIX}sol02_garden_plan_tests"
)
