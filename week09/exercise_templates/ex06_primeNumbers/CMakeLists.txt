#[===[ Library ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}ex06_primeNumbers_lib"
    "lib/primes.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}ex06_primeNumbers_lib" PUBLIC
    "lib"
)

#[===[ Tests ]===]

add_executable("${CPL_TARGET_WEEK_PREFIX}ex06_primeNumbers_tests"
    "tests/Tests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex06_primeNumbers_tests" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex06_primeNumbers_lib"
    "cpl::boost"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}ex06_primeNumbers_tests"
    COMMAND "${CPL_TARGET_WEEK_PREFIX}ex06_primeNumbers_tests"
)
