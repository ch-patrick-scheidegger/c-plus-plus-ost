# Install script for directory: C:/Users/Pat/CLionProjects/cpl/week04

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/CPL")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/msys64/mingw64/bin/objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/lecture_examples/01_functions_right_or_wrong/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/lecture_examples/02_function_overloading/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/lecture_examples/03_function_ambiguity/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/lecture_examples/04_function_default_arguments/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/lecture_examples/05_function_function_parameters/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/lecture_examples/06_functions_right_or_wrong_2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/lecture_examples/07_lambdas/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/lecture_examples/08_functions_right_or_wrong_3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/lecture_examples/09_function_argument_resolution_sequence/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/lecture_examples/10_error_handling_undefined_behavior/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/lecture_examples/11_error_handling_default_result/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/lecture_examples/12_error_handling_error_value/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/lecture_examples/13_error_handling_optional_return_value/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/lecture_examples/14_error_handling_status_side_effect/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/lecture_examples/15_error_handling_exception/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/lecture_examples/16_error_handling_right_or_wrong/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/lecture_examples/17_noexcept/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/exercise_templates/ex00_fizzbuzz/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/exercise_templates/ex01_pocketcalculator/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/exercise_templates/ex02_wlist/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/exercise_templates/ex03_countingToLower/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/exercise_templates/ex04_printFunctionTable/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/exercise_templates/ex05_timingMeasurement/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/exercise_solutions/sol02_wlist/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/exercise_solutions/sol03_countingToLower/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Pat/CLionProjects/cpl/cmake-build-debug/week04/exercise_solutions/sol04_printFunctionTable/cmake_install.cmake")
endif()

