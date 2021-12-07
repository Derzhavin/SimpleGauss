get_filename_component(project_dir ${CMAKE_CURRENT_LIST_DIR} NAME)
project(${project_dir})

file(GLOB LIB_SOURCES "*.cpp" "*.c")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CUDA_SEPARABLE_COMPILATION ON)
set(CMAKE_CUDA_COMPILER "/usr/local/cuda/bin/nvcc")

file(GLOB CPP_SOURCES "*.cpp")
file(GLOB C_SOURCES "*.c")
file(GLOB CUDA_SOURCES "*.cu")

if(UNIX)
    string(APPEND CMAKE_CXX_FLAGS " -fPIC")
    string(APPEND CMAKE_C_FLAGS " -fPIC")
endif()

find_package(CUDA 11 REQUIRED)
enable_language(CUDA)

cuda_include_directories(${CUDA_INCLUDE_DIRS})
cuda_add_library(${PROJECT_NAME} SHARED ${CUDA_SOURCES} ${CPP_SOURCES})
target_link_libraries(${PROJECT_NAME} ${CUDA_LIBRARIES})