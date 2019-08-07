cmake_minimum_required(VERSION 3.14)


if (NOT TARGET rasterization)
    add_subdirectory(../Rasterization ../Rasterization)
endif ()

add_executable(ColorTest ColorTest.cpp)
target_include_directories(ColorTest PRIVATE ../Rasterization)
target_link_libraries(ColorTest PRIVATE raster)

add_executable(DrawAPoint DrawAPoint.cpp)
target_include_directories(DrawAPoint PRIVATE ../Rasterization)
target_link_libraries(DrawAPoint PRIVATE raster)