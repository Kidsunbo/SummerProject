cmake_minimum_required(VERSION 3.14)


if (NOT TARGET rasterization)
    add_subdirectory(../Rasterization ../Rasterization)
endif ()

add_executable(TestFunction TestFunction.cpp)
target_include_directories(TestFunction PRIVATE ../Rasterization)
target_link_libraries(TestFunction PRIVATE raster)

add_executable(DrawAPoint DrawAPoint.cpp)
target_include_directories(DrawAPoint PRIVATE ../Rasterization)
target_link_libraries(DrawAPoint PRIVATE raster)

add_executable(DrawALine DrawALine.cpp)
target_include_directories(DrawALine PRIVATE ../Rasterization)
target_link_libraries(DrawALine PRIVATE raster)