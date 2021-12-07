cmake_minimum_required(VERSION 3.16)
project(SimpleGauss)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CUDA_SEPARABLE_COMPILATION ON)

string(APPEND CMAKE_CXX_FLAGS " -std=c++11 -pthread")

add_subdirectory(matrix)
add_subdirectory(computationAPI)
add_subdirectory(simpleGauss)
add_subdirectory(test)