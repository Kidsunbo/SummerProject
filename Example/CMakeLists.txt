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

add_executable(DrawATriangle DrawATriangle.cpp)
target_include_directories(DrawATriangle PRIVATE ../Rasterization)
target_link_libraries(DrawATriangle PRIVATE raster)

add_executable(DrawACube DrawACube.cpp)
target_include_directories(DrawACube PRIVATE ../Rasterization)
target_link_libraries(DrawACube PRIVATE raster)

add_executable(DrawCubeWithLight DrawCubeWithLight.cpp)
target_include_directories(DrawCubeWithLight PRIVATE ../Rasterization)
target_link_libraries(DrawCubeWithLight PRIVATE raster)

add_executable(DrawACat DrawACat.cpp)
target_include_directories(DrawACat PRIVATE ../Rasterization)
target_link_libraries(DrawACat PRIVATE raster)

add_executable(DrawADeer DrawADeer.cpp)
target_include_directories(DrawADeer PRIVATE ../Rasterization)
target_link_libraries(DrawADeer PRIVATE raster)

add_executable(DrawATriangleWithTexture DrawATriangleWithTexture.cpp)
target_include_directories(DrawATriangleWithTexture PRIVATE ../Rasterization)
target_link_libraries(DrawATriangleWithTexture PRIVATE raster)