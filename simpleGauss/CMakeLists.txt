get_filename_component(project_dir ${CMAKE_CURRENT_LIST_DIR} NAME)
project(${project_dir})

file(GLOB LIB_SOURCES "*.cpp" "*.c")
list(REMOVE_ITEM LIB_SOURCES "main_simple_gauss_cpu_example.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)
add_library(${PROJECT_NAME} SHARED ${LIB_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE matrix computationAPI)

add_executable(${PROJECT_NAME}_simple_gauss_cpu_example main_simple_gauss_cpu_example.cpp)
target_link_libraries(${PROJECT_NAME}_simple_gauss_cpu_example ${PROJECT_NAME})
