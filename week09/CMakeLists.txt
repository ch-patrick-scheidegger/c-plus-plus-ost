set(CPL_TARGET_WEEK_PREFIX "w09_")

file(COPY
    "chapter_6.txt"
    "lorem_ipsum.txt"
    DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)

#[====[ SOLUTIONS ]====]

add_subdirectory("exercise_solutions/sol01_median")
add_subdirectory("exercise_solutions/sol02_rotate3arguments")
add_subdirectory("exercise_solutions/sol03_readln")
# add_subdirectory("exercise_solutions/sol04_wordCount") ## ONLY WORKS WITH REAL "WORD" SOLUTION
# add_subdirectory("exercise_solutions/sol05_nthWord") ## ONLY WORKS WITH REAL "WORD" SOLUTION
add_subdirectory("exercise_solutions/sol06_primeNumbers")
# add_subdirectory("exercise_solutions/sol07_wlistFunctors") ## ONLY WORKS WITH REAL "WORD" SOLUTION
# add_subdirectory("exercise_solutions/sol08_wordLineOccurrence") ## ONLY WORKS WITH REAL "WORD" SOLUTION

#[====[ TEMPLATES ]====]

add_subdirectory("exercise_templates/ex01_median")
add_subdirectory("exercise_templates/ex02_rotate3arguments")
add_subdirectory("exercise_templates/ex03_readln")
# add_subdirectory("exercise_templates/ex04_wordCount") ## ONLY WORKS WITH REAL "WORD" SOLUTION
# add_subdirectory("exercise_templates/ex05_nthWord") ## ONLY WORKS WITH REAL "WORD" SOLUTION
add_subdirectory("exercise_templates/ex06_primeNumbers")
# add_subdirectory("exercise_templates/ex07_wlistFunctors") ## ONLY WORKS WITH REAL "WORD" SOLUTION
# add_subdirectory("exercise_templates/ex08_wordLineOccurrence") ## ONLY WORKS WITH REAL "WORD" SOLUTION
