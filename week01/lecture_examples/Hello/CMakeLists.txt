#[===[ LIBRARY ]===]

add_library("Hello" STATIC
    "lib/HelloFunction.cpp"
    "lib/HelloStruct.cpp"
)

target_include_directories("Hello" PUBLIC
    "lib"
)

#[===[ TESTS ]===]

add_executable("SayHelloTests"
    "test/HelloTests.cpp"
)

target_link_libraries("SayHelloTests" PRIVATE
    "Hello"
    "cpl::cute"
)

add_test(NAME "SayHelloTests" COMMAND "SayHelloTests")

#[===[ APPLICATION ]===]

add_executable("SayHelloApp"
    "app/HelloMain.cpp"
)

target_link_libraries("SayHelloApp" PRIVATE
    "Hello"
)
