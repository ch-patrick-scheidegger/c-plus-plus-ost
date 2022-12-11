#[====[ Library ]====]

add_library("${CPL_TARGET_WEEK_PREFIX}ex01_inheritance" INTERFACE)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}ex01_inheritance" INTERFACE
    "lib"
)

#[====[ Application ]====]

add_executable("${CPL_TARGET_WEEK_PREFIX}ex01_inheritance_demo"
    "app/main.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}ex01_inheritance_demo" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}ex01_inheritance"
)
