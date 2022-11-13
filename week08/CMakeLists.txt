set(CPL_TARGET_WEEK_PREFIX "w08_")

add_subdirectory("lecture_examples/01_reverse")
add_subdirectory("lecture_examples/02_max_element")
add_subdirectory("lecture_examples/03_performance")
add_subdirectory("lecture_examples/04_redirect")
add_subdirectory("lecture_examples/05_average")
add_subdirectory("lecture_examples/06_transform")
add_subdirectory("lecture_examples/07_merge")
add_subdirectory("lecture_examples/08_erase_remove")
add_subdirectory("lecture_examples/09_accumulate")

add_subdirectory("lecture_examples/quiz_01_merge")
add_subdirectory("lecture_examples/quiz_02_splitDigits")
add_subdirectory("lecture_examples/quiz_03_primes")

add_subdirectory("exercise_templates/ex02_algorithm_trivia")

file(COPY "exercise_solutions/sol03_palindromes/linuxwords.txt"
    DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)
add_subdirectory("exercise_solutions/sol03_palindromes")
add_subdirectory("exercise_solutions/sol04_anagrams")
add_subdirectory("exercise_solutions/sol04_anagrams_multiwords")
add_subdirectory("exercise_solutions/sol04_anagrams_multiwords_optimized")
