add_library("${CPL_TARGET_WEEK_PREFIX}lecture02_static_member_of_template_lib" INTERFACE)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}lecture02_static_member_of_template_lib" INTERFACE
    "lib"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}lecture02_static_member_of_template"
    "app/main.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}lecture02_static_member_of_template" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}lecture02_static_member_of_template_lib"
)
