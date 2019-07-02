cmake_minimum_required(VERSION 3.14)
project(Test)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Painter)

add_executable(RandomPixels RandomPixels.cpp)
add_executable(RandomLines RandomLines.cpp)
add_executable(BlackWindow BlackWindow.cpp)
add_executable(DrawTriangle DrawTriangle.cpp)

# Dependency for RandomPixels
target_include_directories(RandomPixels PRIVATE Painter)
target_link_libraries(RandomPixels PRIVATE painter)

# Dependency for RandomLines
target_include_directories(RandomLines PRIVATE Painter)
target_link_libraries(RandomLines PRIVATE painter)

# Dependency for BlackWindow
target_include_directories(BlackWindow PRIVATE glfw-3.3/include)
target_link_libraries(BlackWindow PRIVATE painter)

# Dependency for DrawTriangle
target_include_directories(DrawTriangle PRIVATE Painter)
target_link_libraries(DrawTriangle PRIVATE painter)