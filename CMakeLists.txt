cmake_minimum_required(VERSION 3.16)
project(SimpleGauss)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CUDA_SEPARABLE_COMPILATION ON)

if(UNIX)
    string(APPEND CMAKE_CXX_FLAGS " -std=c++11 -pthread -fPIC")
    string(APPEND CMAKE_CUDA_FLAGS " -cudart shared -gencode arch=compute_75,code=sm_75 -O3 --compiler-options -fPIC")
elseif(WIN32)
    string(APPEND CMAKE_CXX_FLAGS " /std:c++11")
endif()

if(CMAKE_BUILD_TYPE STREQUAL Release)
    if (UNIX)

    elseif(WIN32)

    endif()
endif()

add_subdirectory(matrix)
add_subdirectory(computationAPI)
add_subdirectory(simpleGauss)
add_subdirectory(test)