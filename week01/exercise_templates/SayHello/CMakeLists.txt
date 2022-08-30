#[===[ LIBRARY ]===]

add_library("SayHello" STATIC
    "lib/SayHello.cpp"
)

target_include_directories("SayHello" PUBLIC
    "lib"
)

target_compile_features("SayHello" PUBLIC
    "cxx_std_20"
)

#[===[ TESTS ]===]

add_executable("SayHelloTests"
    "test/Test.cpp"
)

target_link_libraries("SayHelloTests" PRIVATE
    "SayHello"
    "cpl::cute"
)

add_test(NAME "SayHelloTests" COMMAND "SayHelloTests")

#[===[ APPLICATION ]===]

add_executable("SayHelloApp"
    "app/SayHelloApp.cpp"
)

target_link_libraries("SayHelloApp" PRIVATE
    "SayHello"
)