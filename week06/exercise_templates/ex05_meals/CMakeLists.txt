#[===[ LIBRARY ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}ex05_meals_lib"
    "lib/Meal.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}ex05_meals_lib" PUBLIC "lib")

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex05_meals_lib" PUBLIC "cpl::boost")


#[===[ TESTS ]===]


add_executable("${CPL_TARGET_WEEK_PREFIX}ex05_meals_tests"
    "tests/MealTests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex05_meals_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex05_meals_lib"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}ex05_meals_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}ex05_meals_tests")