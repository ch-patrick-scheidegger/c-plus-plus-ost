#[===[ LIBRARY ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}ex01_pocketcalculator"
    "lib/Pocketcalculator.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}ex01_pocketcalculator" PUBLIC "lib")


#[===[ APPLICATION ]===]

add_executable("${CPL_TARGET_WEEK_PREFIX}ex01_pocketcalculator_app"
"app/PocketcalculatorApp.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex01_pocketcalculator_app" PRIVATE
"${CPL_TARGET_WEEK_PREFIX}ex01_pocketcalculator"
)


#[===[ TESTS ]===]


add_executable("${CPL_TARGET_WEEK_PREFIX}ex01_pocketcalculator_tests"
    "tests/PocketcalculatorTests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex01_pocketcalculator_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex01_pocketcalculator"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}ex01_pocketcalculator_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}ex01_pocketcalculator_tests")
