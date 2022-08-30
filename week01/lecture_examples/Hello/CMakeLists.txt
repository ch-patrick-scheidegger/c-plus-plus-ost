#[===[ LIBRARY ]===]

add_library("Hello" STATIC
    "lib/HelloFunction.cpp"
    "lib/HelloStruct.cpp"
)

target_include_directories("Hello" PUBLIC
    "lib"
)

target_compile_features("Hello" PUBLIC
    "cxx_std_20"
)

#[===[ TESTS ]===]

add_executable("HelloTests"
    "test/HelloTests.cpp"
)

target_link_libraries("HelloTests" PRIVATE
    "Hello"
    "cpl::cute"
)

add_test(NAME "HelloTests" COMMAND "HelloTests")

#[===[ APPLICATION ]===]

add_executable("HelloApp"
    "app/HelloMain.cpp"
)

target_link_libraries("HelloApp" PRIVATE
    "Hello"
)
