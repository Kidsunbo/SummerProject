cmake_minimum_required(VERSION 3.14)

if(NOT TARGET painter)
    add_subdirectory(../Painter ../Painter)
endif()

add_executable(RandomPixels RandomPixels.cpp)
add_executable(RandomLines RandomLines.cpp)
add_executable(BlackWindow BlackWindow.cpp)
add_executable(RandomTriangles RandomTriangles.cpp)
add_executable(RandomCircle RandomCircle.cpp)
add_executable(RandomShapes RandomShapes.cpp)


# Dependency for RandomPixels
target_include_directories(RandomPixels PRIVATE ../Painter)
target_link_libraries(RandomPixels PRIVATE painter)

# Dependency for RandomLines
target_include_directories(RandomLines PRIVATE ../Painter)
target_link_libraries(RandomLines PRIVATE painter)

# Dependency for BlackWindow
target_include_directories(BlackWindow PRIVATE ../glfw-3.3/include)
target_link_libraries(BlackWindow PRIVATE painter)

# Dependency for RandomTriangles
target_include_directories(RandomTriangles PRIVATE ../Painter)
target_link_libraries(RandomTriangles PRIVATE painter)

# Dependency for RandomCircle
target_include_directories(RandomCircle PRIVATE ../Painter)
target_link_libraries(RandomCircle PRIVATE painter)

# Dependency for RandomShapes
target_include_directories(RandomShapes PRIVATE ../Painter)
target_link_libraries(RandomShapes PRIVATE painter)