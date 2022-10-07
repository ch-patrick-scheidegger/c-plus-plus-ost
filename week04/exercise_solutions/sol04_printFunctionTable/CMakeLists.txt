#[===[ LIBRARY ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}sol04_printFunctionTable"
    "lib/PrintFunctionTable.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}sol04_printFunctionTable" PUBLIC "lib")

#[===[ APPLICATION ]===]
add_executable("${CPL_TARGET_WEEK_PREFIX}sol04_printFunctionTable_app"
    "app/PrintFunctionTableApp.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol04_printFunctionTable_app" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol04_printFunctionTable"
)


#[===[ TESTS ]===]
add_executable("${CPL_TARGET_WEEK_PREFIX}sol04_printFunctionTable_tests"
    "tests/PrintFunctionTableTests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol04_printFunctionTable_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol04_printFunctionTable"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}sol04_printFunctionTable_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}sol04_printFunctionTable_tests")