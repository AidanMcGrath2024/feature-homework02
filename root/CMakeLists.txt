cmake_minimum_required(VERSION 3.23) # Specify CMake version.
project(homework
    VERSION 1.0
    DESCRIPTION "Homework 02"
    LANGUAGES CXX)# A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # Specify C++ version.
include_directories(${CMAKE_SOURCE_DIR}/include) # header file folder.
message("Project Dir = " ${CMAKE_PROJECT_NAME})
message("Source  Dir = " ${CMAKE_SOURCE_DIR})
add_executable(${CMAKE_PROJECT_NAME}
    src/main.cpp
    src/engine.cpp
    src/utils.cpp
    ) # source files. may add *.hpp in this function as well if the include_directories is wonky
