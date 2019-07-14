cmake_minimum_required(VERSION 3.14)

set(GLAD ../glfw-3.3/deps/glad_gl.c)

aux_source_directory(. SOURCE_FILES)

if(NOT TARGET glfw)
    add_subdirectory(../glfw-3.3 ../glfw-3.3)
endif()
if(NOT TARGET painter)
    add_library(painter ${SOURCE_FILES} ${GLAD})
endif()

target_include_directories(painter PUBLIC ../glfw-3.3/include)
target_include_directories(painter PUBLIC ../glfw-3.3/deps)

if(WIN32)
    target_link_libraries(painter PUBLIC glfw opengl32)
endif()

if(APPLE)
    find_package(OpenGL)
    target_link_libraries(painter PUBLIC glfw ${OPENGL_LIBRARIES})
endif()