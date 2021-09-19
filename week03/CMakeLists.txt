cmake_minimum_required(VERSION 3.19)

project(w03 LANGUAGES CXX)

week_executable(NAME "algorithmdemo"
    SOURCES
    lecture_examples/algorithmdemo/algorithmdemo.cpp
)

week_executable(NAME "cat"
    SOURCES
    lecture_examples/cat/cat.cpp
)

week_executable(NAME "copycat"
    SOURCES
    lecture_examples/copycat/copycat.cpp
)

week_executable(NAME "vectordemo"
    SOURCES
    lecture_examples/vectordemo/vectordemo.cpp
)

week_test(NAME "ex3a_charc"
    SOURCES
    exercise_templates/ex3a_charc/src/charc.cpp
    exercise_templates/ex3a_charc/src/Test.cpp
    INCLUDE_DIRECTORIES
    exercise_templates/ex3a_charc/cute
)

week_test(NAME "ex3b_allcharc"
    SOURCES
    exercise_templates/ex3b_allcharc/src/allcharc.cpp
    exercise_templates/ex3b_allcharc/src/Test.cpp
    INCLUDE_DIRECTORIES
    exercise_templates/ex3b_allcharc/cute
)

week_test(NAME "ex3c_wc"
    SOURCES
    exercise_templates/ex3c_wc/src/wc.cpp
    exercise_templates/ex3c_wc/src/Test.cpp
    INCLUDE_DIRECTORIES
    exercise_templates/ex3c_wc/cute
)

week_test(NAME "ex3d_lc"
    SOURCES
    exercise_templates/ex3d_lc/src/lc.cpp
    exercise_templates/ex3d_lc/src/Test.cpp
    INCLUDE_DIRECTORIES
    exercise_templates/ex3d_lc/cute
)

week_test(NAME "sol2a_charc"
    SOURCES
    exercise_solutions/sol2a_charc/src/charc.cpp
    exercise_solutions/sol2a_charc/src/Test.cpp
    INCLUDE_DIRECTORIES
    exercise_solutions/sol2a_charc/cute
)

week_test(NAME "sol2b_allcharc"
    SOURCES
    exercise_solutions/sol2b_allcharc/src/allcharc.cpp
    exercise_solutions/sol2b_allcharc/src/Test.cpp
    INCLUDE_DIRECTORIES
    exercise_solutions/sol2b_allcharc/cute
)

week_test(NAME "sol2c_wc"
    SOURCES
    exercise_solutions/sol2c_wc/src/wc.cpp
    exercise_solutions/sol2c_wc/src/Test.cpp
    INCLUDE_DIRECTORIES
    exercise_solutions/sol2c_wc/cute
)

week_test(NAME "sol2d_lc"
    SOURCES
    exercise_solutions/sol2d_lc/src/lc.cpp
    exercise_solutions/sol2d_lc/src/Test.cpp
    INCLUDE_DIRECTORIES
    exercise_solutions/sol2d_lc/cute
)

week_test(NAME "sol4_sumi"
    SOURCES
    exercise_solutions/sol4_sumi/src/sumi.cpp
    exercise_solutions/sol4_sumi/src/Test.cpp
    INCLUDE_DIRECTORIES
    exercise_solutions/sol4_sumi/cute
)

week_executable(NAME "sol5_multab"
    SOURCES
    exercise_solutions/sol5_multab/multab.cpp
)

week_executable(NAME "sol6_fracttab"
    SOURCES
    exercise_solutions/sol6_fracttab/fracttab.cpp
)
