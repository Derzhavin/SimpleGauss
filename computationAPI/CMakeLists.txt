get_filename_component(project_dir ${CMAKE_CURRENT_LIST_DIR} NAME)
project(${project_dir})

file(GLOB LIB_SOURCES "*.cpp" "*.c")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)
add_library(${PROJECT_NAME} SHARED ${LIB_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE matrix)