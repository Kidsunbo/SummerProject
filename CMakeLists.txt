cmake_minimum_required(VERSION 3.14)
project(Test)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(glfw-3.3)

set(GLAD glfw-3.3/deps/glad_gl.c RandomPixels.cpp Painter.cpp Painter.h)

add_library(painter Painter.cpp)

add_executable(Test RandomPixels.cpp ${GLAD})

target_include_directories(Test PRIVATE glfw-3.3/include)
target_include_directories(Test PRIVATE glfw-3.3/deps)
target_include_directories(painter PRIVATE glfw-3.3/include)
target_include_directories(painter PRIVATE glfw-3.3/deps)
target_link_libraries(Test PRIVATE glfw opengl32 painter)

