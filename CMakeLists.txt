cmake_minimum_required(VERSION 3.10)
project(SimpleGauss)

string(APPEND CMAKE_CXX_FLAGS " -std=c++17")
add_subdirectory(matrix)
add_subdirectory(computationAPI)
add_subdirectory(simpleGauss)