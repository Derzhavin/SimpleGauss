cmake_minimum_required(VERSION 3.16)
get_filename_component(project_dir ${CMAKE_CURRENT_LIST_DIR} NAME)
project(${project_dir})

enable_language(CUDA)

find_package(GTest REQUIRED)
include_directories(
    ${GTEST_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES}
)

file(GLOB SOURCES "*.c" "*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread simpleGauss)