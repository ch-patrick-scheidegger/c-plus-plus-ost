cmake_minimum_required(VERSION 3.19)

add_executable(charc_test
  src/Test.cpp
  src/charc.cpp
)

target_include_directories(charc_test PRIVATE cute)