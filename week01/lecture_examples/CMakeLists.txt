
add_subdirectory(helloworld)

add_library(HelloLib Hello/Hello.cpp Hello/sayhello.cpp)

add_executable(HelloMain HelloMain/hellomain.cpp)
target_include_directories(HelloMain PUBLIC Hello)
target_link_libraries(HelloMain HelloLib)

add_executable(HelloTest HelloTest/src/Test.cpp)
target_include_directories(HelloTest PUBLIC Hello HelloTest/cute)
target_link_libraries(HelloTest HelloLib)