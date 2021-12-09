cmake_minimum_required(VERSION 3.16)
get_filename_component(project_dir ${CMAKE_CURRENT_LIST_DIR} NAME)
project(${project_dir})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CUDA_SEPARABLE_COMPILATION ON)
set(CMAKE_CUDA_COMPILER "/usr/local/cuda/bin/nvcc")

file(GLOB CPP_SOURCES "*.cpp")
file(GLOB C_SOURCES "*.c")
file(GLOB CUDA_SOURCES "*.cu")

list(REMOVE_ITEM CPP_SOURCES "main_api_example.cpp")
list(REMOVE_ITEM C_SOURCES "main_api_example.cpp")

find_package(CUDA 11 REQUIRED)
enable_language(CUDA)

cuda_include_directories(${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES})

cuda_add_library(${PROJECT_NAME} SHARED ${CUDA_SOURCES} ${CPP_SOURCES} ${C_SOURCES})
target_link_libraries(${PROJECT_NAME} ${CUDA_LIBRARIES})

add_executable(${PROJECT_NAME}_cuda_api_example main_api_example.cpp)
target_link_libraries(${PROJECT_NAME}_cuda_api_example ${PROJECT_NAME})