#[===[ LIBRARY ]===]

add_library("HelloLib" STATIC
    "lib/Hello.cpp"
)

target_include_directories("HelloLib" PUBLIC
    "lib"
)


#[===[ TESTS ]===]

add_executable("HelloTests"
    "test/HelloTest.cpp"
)

target_link_libraries("HelloTests" PRIVATE
    "HelloLib"
    "cpl::cute"
)

add_test(NAME "HelloTests" COMMAND "HelloTests")

#[===[ APPLICATION ]===]

add_executable("HelloApp"
    "app/HelloApp.cpp"
)

target_link_libraries("HelloApp" PRIVATE
    "HelloLib"
)