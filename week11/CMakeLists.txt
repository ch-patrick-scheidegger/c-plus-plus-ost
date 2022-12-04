set(CPL_TARGET_WEEK_PREFIX "w11_")

file(COPY
    "LargeCatalogue_expected_topological.txt"
    "LargeCatalogue.txt"
    DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)

add_subdirectory("lecture_examples/lecture01_unique_ptr_ownership")
add_subdirectory("lecture_examples/lecture02_c_apis")
add_subdirectory("lecture_examples/lecture03_ostream_ptr")
add_subdirectory("lecture_examples/lecture04_shared_ptr_lights")

add_subdirectory("exercise_templates/ex01_indexable_set")
add_subdirectory("exercise_templates/ex02_dyn_array")
add_subdirectory("exercise_templates/ex03_module_sort")

add_subdirectory("exercise_solutions/sol02_dyn_array")
add_subdirectory("exercise_solutions/sol03_module_sort")
add_subdirectory("exercise_solutions/sol03_module_sort_fast")