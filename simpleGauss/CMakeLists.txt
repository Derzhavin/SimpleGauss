cmake_minimum_required(VERSION 3.16)
get_filename_component(project_dir ${CMAKE_CURRENT_LIST_DIR} NAME)
project(${project_dir})

file(GLOB_RECURSE LIB_SOURCES "*.cpp" "*.c" "*.cu")

list(FILTER LIB_SOURCES EXCLUDE REGEX "main_simple_gauss_cpu_example.cpp")
list(FILTER LIB_SOURCES EXCLUDE REGEX "main_simple_gauss_cuda_example.cpp")

enable_language(CUDA)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES}
)

cuda_add_library(${PROJECT_NAME} SHARED ${LIB_SOURCES})
target_link_libraries(${PROJECT_NAME} matrix computationAPI)

add_executable(${PROJECT_NAME}_simple_gauss_cpu_example main_simple_gauss_cpu_example.cpp)
target_link_libraries(${PROJECT_NAME}_simple_gauss_cpu_example ${PROJECT_NAME})

add_executable(${PROJECT_NAME}_simple_gauss_cuda_example main_simple_gauss_cuda_example.cpp)
target_link_libraries(${PROJECT_NAME}_simple_gauss_cuda_example ${PROJECT_NAME})