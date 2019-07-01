cmake_minimum_required(VERSION 3.14)
project(Test)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Painter)

add_executable(RandomPixels RandomPixels.cpp)
add_executable(RandomLines RandomLines.cpp)

target_include_directories(RandomPixels PRIVATE Painter)
target_link_libraries(RandomPixels PRIVATE painter)
target_include_directories(RandomLines PRIVATE Painter)
target_link_libraries(RandomLines PRIVATE painter)

