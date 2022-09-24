#[===[ LIBRARY ]===]

add_library("HelloLib" STATIC
    "lib/Hello.cpp"
)

target_include_directories("HelloLib" PUBLIC
    "lib"
)


#[===[ TESTS ]===]

add_executable("${CPL_TARGET_WEEK_PREFIX}HelloTests"
    "test/HelloTest.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}HelloTests" PRIVATE
    "HelloLib"
    "cpl::cute"
)

add_test(NAME "${CPL_TARGET_WEEK_PREFIX}HelloTests" COMMAND "HelloTests")

#[===[ APPLICATION ]===]

add_executable("${CPL_TARGET_WEEK_PREFIX}HelloApp"
    "app/HelloApp.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}HelloApp" PRIVATE
    "HelloLib"
)