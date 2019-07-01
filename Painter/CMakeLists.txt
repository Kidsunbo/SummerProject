cmake_minimum_required(VERSION 3.14)

set(GLAD ../glfw-3.3/deps/glad_gl.c)

aux_source_directory(. SOURCE_FILES)

add_subdirectory(../glfw-3.3 ../glfw-3.3)

add_library(painter ${SOURCE_FILES} ${GLAD})

target_include_directories(painter PUBLIC ../glfw-3.3/include)
target_include_directories(painter PUBLIC ../glfw-3.3/deps)

target_link_libraries(painter PUBLIC glfw opengl32)