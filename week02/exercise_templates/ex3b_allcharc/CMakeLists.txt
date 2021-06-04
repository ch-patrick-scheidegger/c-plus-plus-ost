cmake_minimum_required(VERSION 3.19)

add_executable(allcharc_test
  src/Test.cpp
  src/allcharc.cpp
)

target_include_directories(allcharc_test PRIVATE cute)