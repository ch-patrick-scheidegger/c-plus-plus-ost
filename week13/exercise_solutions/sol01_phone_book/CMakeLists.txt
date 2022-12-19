#[====[ Library ]====]

add_library("${CPL_TARGET_WEEK_PREFIX}sol01_phone_book_lib" INTERFACE)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}sol01_phone_book_lib" INTERFACE
    "lib"
)

#[====[ Application ]====]

add_executable("${CPL_TARGET_WEEK_PREFIX}sol01_phone_book"
    "app/main.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol01_phone_book" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol01_phone_book_lib"
)

#[====[ Application ]====]

add_executable("${CPL_TARGET_WEEK_PREFIX}sol01_phone_book_tests"
    "tests/main.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol01_phone_book_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}sol01_phone_book_lib"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}sol01_phone_book_tests"
    COMMAND "${CPL_TARGET_WEEK_PREFIX}sol01_phone_book_tests"
)
