cmake_minimum_required(VERSION 3.14)

aux_source_directory(./Graphics Graphics)
aux_source_directory(./Window Window)
aux_source_directory(./Exception Exception)
aux_source_directory(./Math Math)

set(GLAD ../glfw-3.3/deps/glad_gl.c)

set(SOURCE ${Graphics} ${Window} ${Exception} ${Math} Graphics/Line.cpp Graphics/Line.h)

if(NOT TARGET glfw)
    add_subdirectory(../glfw-3.3 ../glfw-3.3)
endif()

add_library(raster ${SOURCE} ${GLAD})

target_include_directories(raster PUBLIC ../Rasterization)
target_include_directories(raster PUBLIC ../glfw-3.3/include)
target_include_directories(raster PUBLIC ../glfw-3.3/deps)

if(WIN32)
    target_link_libraries(raster PUBLIC glfw opengl32)
endif()

if(APPLE)
    find_package(OpenGL)
    target_link_libraries(raster PUBLIC glfw ${OPENGL_LIBRARIES})
endif()