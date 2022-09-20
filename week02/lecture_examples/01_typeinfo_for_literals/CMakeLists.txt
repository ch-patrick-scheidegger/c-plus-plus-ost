#[===[ APPLICATION ]===]

add_executable("01_typeinfo_for_literals"
    "typeinfo_for_literals.cpp"
)


target_link_libraries("01_typeinfo_for_literals" PUBLIC "cpl::boost")