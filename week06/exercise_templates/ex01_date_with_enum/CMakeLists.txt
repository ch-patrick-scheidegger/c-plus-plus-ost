#[===[ LIBRARY ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}ex01_date_wit_enum_lib"
    "lib/Date.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}ex01_date_wit_enum_lib" PUBLIC "lib")



#[===[ TESTS ]===]


add_executable("${CPL_TARGET_WEEK_PREFIX}ex01_date_wit_enum_tests"
    "tests/DateWithEnumTests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex01_date_wit_enum_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex01_date_wit_enum_lib"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}ex01_date_wit_enum_tests" COMMAND "${CPL_TARGET_WEEK_PREFIX}ex01_date_wit_enum_tests")