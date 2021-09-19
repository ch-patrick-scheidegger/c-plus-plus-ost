cmake_minimum_required(VERSION 3.19)

project(w01 LANGUAGES CXX)

week_executable(NAME "say_hello"
    SOURCES
    exercise_templates/mainsayhello.cpp
    exercise_templates/sayhello.cpp
)

week_executable(NAME "helloworld"
    SOURCES
    lecture_examples/helloworld/helloworld.cpp
)

week_library(NAME "HelloLib"
    SOURCES
    lecture_examples/Hello/Hello.cpp
    lecture_examples/Hello/sayhello.cpp
    INCLUDE_DIRECTORIES
    lecture_examples/Hello
)

week_executable(NAME "HelloMain"
    SOURCES
    lecture_examples/HelloMain/hellomain.cpp
    LIBRARIES
    w01_HelloLib
)

week_test(NAME "HelloTest"
    SOURCES
    lecture_examples/HelloTest/src/Test.cpp
    INCLUDE_DIRECTORIES
    lecture_examples/HelloTest/cute
    LIBRARIES
    w01_HelloLib
)