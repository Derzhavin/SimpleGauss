get_filename_component(project_dir ${CMAKE_CURRENT_LIST_DIR} NAME)
project(${project_dir})

file(GLOB LIB_SOURCES "*.cpp" "*.c")
list(REMOVE_ITEM LIB_SOURCES "main_mat.cpp")

find_package(nlohmann_json 3.2.0 REQUIRED)

add_definitions(-DDEBUG_FIXED_MAT)
add_executable(${project_dir}_example main_mat.cpp)

add_library(${PROJECT_NAME} SHARED ${LIB_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)