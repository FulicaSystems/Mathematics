# CMake version
cmake_minimum_required(VERSION 3.21)

# C++ standard version
set(CMAKE_CXX_STANDARD 20)

set(PROJECT_NAME Mathematics)

option(BUILD_TESTS "build tests" ON)

# initiating project given its name
project(${PROJECT_NAME})

add_subdirectory(fumathematics)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()