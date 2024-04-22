cmake_minimum_required(VERSION 3.14)


find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)

add_library(raster)
target_include_directories(raster PUBLIC include)
target_link_libraries(raster PUBLIC glfw glad::glad)


add_subdirectory(src/math)
add_subdirectory(src/window)
add_subdirectory(src/graphics)
add_subdirectory(src/exception)
