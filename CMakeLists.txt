cmake_minimum_required(VERSION 3.0.0)
project(allocator VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 14)
include(CTest)
enable_testing()

add_executable(allocator main.cpp)

add_library(allocatorlib allocator.cpp)

target_link_libraries(allocator allocatorlib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
