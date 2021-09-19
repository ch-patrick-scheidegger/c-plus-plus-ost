cmake_minimum_required(VERSION 3.19)

project(w02 LANGUAGES CXX)

week_executable(NAME "01_typeinfo_for_literals"
    SOURCES
    lecture_examples/01_typeinfo_for_literals/typeinfo_for_literals.cpp
)

week_executable(NAME "02_type_conversion_and_ub"
    SOURCES
    lecture_examples/02_type_conversion_and_ub/src/type_conversion_and_ub.cpp
)

week_executable(NAME "03_bad_relational_operator_example"
    SOURCES
    lecture_examples/03_bad_relational_operator_example/bad_relational_operator_example.cpp
)

week_executable(NAME "04_string_literals"
    SOURCES
    lecture_examples/04_string_literals/string_literals.cpp
)

week_executable(NAME "05_greeting"
    SOURCES
    lecture_examples/05_greeting/greeting.cpp
)

week_executable(NAME "06_bad_greeting"
    SOURCES
    lecture_examples/06_bad_greeting/bad_greeting.cpp
)

week_executable(NAME "07_how_old_are_you_fragile"
    SOURCES
    lecture_examples/07_how_old_are_you_fragile/how_old_are_you_fragile.cpp
)

week_executable(NAME "08_charcount_for_eof_demo"
    SOURCES
    lecture_examples/08_charcount_for_eof_demo/charcount.cpp
)

week_executable(NAME "09_how_old_are_you_robust"
    SOURCES
    lecture_examples/09_how_old_are_you_robust/how_old_are_you_robust.cpp
)

week_executable(NAME "10_how_old_are_you_robust_ignoring"
    SOURCES
    lecture_examples/10_how_old_are_you_robust_ignoring/how_old_are_you_robust_ignoring.cpp
)

week_executable(NAME "11_formatted_output"
    SOURCES
    lecture_examples/11_formatted_output/formatted_output.cpp
)

week_executable(NAME "12_tolower_chars"
    SOURCES
    lecture_examples/12_tolower_chars/tolower_chars.cpp
)

week_executable(NAME "recap_quiz"
    SOURCES
    lecture_examples/recap_quiz/main.cpp
    INCLUDE_DIRECTORIES
    lecture_examples/recap_quiz
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

week_executable(NAME "sol3a_charc"
    SOURCES
    exercise_solutions/sol3a_charc/charc.cpp
)

week_executable(NAME "sol3c_wc"
    SOURCES
    exercise_solutions/sol3c_wc/wc.cpp
)

week_executable(NAME "sol3d_lc-getline"
    SOURCES
    exercise_solutions/sol3d_lc-getline/lc.cpp
)

week_executable(NAME "sol3d_lc-newline"
    SOURCES
    exercise_solutions/sol3d_lc-newline/lc.cpp
)

week_executable(NAME "sol5a_sumf"
    SOURCES
    exercise_solutions/sol5a_sumf/sumf.cpp
)

week_executable(NAME "sol5a_sumi"
    SOURCES
    exercise_solutions/sol5a_sumi/sumi.cpp
)

week_executable(NAME "sol5b_allcharc"
    SOURCES
    exercise_solutions/sol5b_allcharc/allcharc.cpp
)

week_executable(NAME "sol5b_averagef"
    SOURCES
    exercise_solutions/sol5b_averagef/averagef.cpp
)

week_executable(NAME "sol5b_averagei"
    SOURCES
    exercise_solutions/sol5b_averagei/averagei.cpp
)

week_executable(NAME "sol5c_multab"
    SOURCES
    exercise_solutions/sol5c_multab/multab.cpp
)

week_executable(NAME "sol5d_fracttab"
    SOURCES
    exercise_solutions/sol5d_fracttab/fracttab.cpp
)
