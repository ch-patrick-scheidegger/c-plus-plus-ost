#[===[ APPLICATION ]===]

add_executable("${CPL_TARGET_WEEK_PREFIX}01_typeinfo_for_literals"
    "typeinfo_for_literals.cpp"
)


target_link_libraries("${CPL_TARGET_WEEK_PREFIX}01_typeinfo_for_literals" PUBLIC "cpl::boost")