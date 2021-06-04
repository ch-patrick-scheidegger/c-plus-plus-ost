cmake_minimum_required(VERSION 3.19)

add_executable(lc_test
  src/Test.cpp
  src/lc.cpp
)

target_include_directories(lc_test PRIVATE cute)