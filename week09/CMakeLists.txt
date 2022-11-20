set(CPL_TARGET_WEEK_PREFIX "w09_")

file(COPY
    "chapter_6.txt"
    "lorem_ipsum.txt"
    DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)

add_subdirectory("exercise_solutions/sol01_median")
add_subdirectory("exercise_solutions/sol02_rotate3arguments")
add_subdirectory("exercise_solutions/sol03_readln")
# add_subdirectory("exercise_solutions/sol04_wordCount") ## ONLY WORKS WITH REAL "WORD" SOLUTION
# add_subdirectory("exercise_solutions/sol05_nthWord") ## ONLY WORKS WITH REAL "WORD" SOLUTION
add_subdirectory("exercise_solutions/sol06_primeNumbers")
# add_subdirectory("exercise_solutions/sol07_wlistFunctors") ## ONLY WORKS WITH REAL "WORD" SOLUTION
# add_subdirectory("exercise_solutions/sol08_wordLineOccurrence") ## ONLY WORKS WITH REAL "WORD" SOLUTION
