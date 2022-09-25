#[===[ LIBRARY ]===]

add_library("Hello" STATIC
    "lib/HelloFunction.cpp"
    "lib/HelloStruct.cpp"
)

target_include_directories("Hello" PUBLIC
    "lib"
)

#[===[ TESTS ]===]

add_executable("${CPL_TARGET_WEEK_PREFIX}SayHelloTests"
    "test/HelloTests.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}SayHelloTests" PRIVATE
    "Hello"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}SayHelloTests" COMMAND "${CPL_TARGET_WEEK_PREFIX}SayHelloTests")

#[===[ APPLICATION ]===]

add_executable("${CPL_TARGET_WEEK_PREFIX}SayHelloApp"
    "app/HelloMain.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}SayHelloApp" PRIVATE
    "Hello"
)
