cmake_minimum_required(VERSION 3.19)

add_executable(wc_test
  src/Test.cpp
  src/wc.cpp
)

target_include_directories(wc_test PRIVATE cute)