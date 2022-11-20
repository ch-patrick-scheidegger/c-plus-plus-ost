#[===[ Apo ]===]

add_library("${CPL_TARGET_WEEK_PREFIX}sol07_wlistFunctors"
    "app/wlist.cpp"
)

target_include_directories("${CPL_TARGET_WEEK_PREFIX}sol07_wlistFunctors" PUBLIC
    "lib"
)

target_link_libraries("${CPL_TARGET_WEEK_PREFIX}sol07_wlistFunctors" PUBLIC
    "w05_ex01_word_lib"
)
