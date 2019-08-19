cmake_minimum_required(VERSION 3.14)


if (NOT TARGET rasterization)
    add_subdirectory(../Rasterization Rasterization)
endif ()

add_executable(Dot Dot.cpp)
target_include_directories(Dot PRIVATE ../Rasterization)
target_link_libraries(Dot PRIVATE raster)

add_executable(Line Line.cpp)
target_include_directories(Line PRIVATE ../Rasterization)
target_link_libraries(Line PRIVATE raster)

add_executable(Triangle Triangle.cpp)
target_include_directories(Triangle PRIVATE ../Rasterization)
target_link_libraries(Triangle PRIVATE raster)

add_executable(TwoTriangle TwoTriangle.cpp)
target_include_directories(TwoTriangle PRIVATE ../Rasterization)
target_link_libraries(TwoTriangle PRIVATE raster)

add_executable(Cube Cube.cpp)
target_include_directories(Cube PRIVATE ../Rasterization)
target_link_libraries(Cube PRIVATE raster)

add_executable(MultiCubes MultiCubes.cpp)
target_include_directories(MultiCubes PRIVATE ../Rasterization)
target_link_libraries(MultiCubes PRIVATE raster)

add_executable(Deer Deer.cpp)
target_include_directories(Deer PRIVATE ../Rasterization)
target_link_libraries(Deer PRIVATE raster)

add_executable(Cat Cat.cpp)
target_include_directories(Cat PRIVATE ../Rasterization)
target_link_libraries(Cat PRIVATE raster)