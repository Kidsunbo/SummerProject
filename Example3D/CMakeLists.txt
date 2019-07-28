cmake_minimum_required(VERSION 3.14)

if(NOT TARGET painter3d)
    add_subdirectory(../Painter3D ../Painter3D)
endif()

add_executable(DrawCube DrawCube.cpp)
target_include_directories(DrawCube PRIVATE ../Painter3D)
target_link_libraries(DrawCube PRIVATE painter3d)
