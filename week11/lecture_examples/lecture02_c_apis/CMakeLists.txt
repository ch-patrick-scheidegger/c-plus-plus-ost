add_library("${CPL_TARGET_WEEK_PREFIX}lecture02_c_apis_lib"
    "lib/demangle.cpp"
    "lib/plain_demangle.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}lecture02_c_apis_lib" PUBLIC
    "lib"
)

add_executable("${CPL_TARGET_WEEK_PREFIX}lecture02_c_apis"
    "app/main.cpp"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}lecture02_c_apis" PRIVATE
    "${CPL_TARGET_WEEK_PREFIX}lecture02_c_apis_lib"
)