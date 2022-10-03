cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(ood LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

# catch2
add_library(catch2 INTERFACE)
target_include_directories(catch2 INTERFACE libs/catch2/)

add_subdirectory(lab1)
add_subdirectory(lab2)
add_subdirectory(lab3)
