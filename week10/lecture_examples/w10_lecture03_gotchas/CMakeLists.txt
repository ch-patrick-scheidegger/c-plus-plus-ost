add_executable("${CPL_TARGET_WEEK_PREFIX}lecture03_gotchas"
    "tests/main.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}lecture03_gotchas" PRIVATE
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}lecture03_gotchas"
    COMMAND "${CPL_TARGET_WEEK_PREFIX}lecture03_gotchas"
)