cmake_minimum_required(VERSION 3.14)
project(SummerProject)

set(CMAKE_CXX_STANDARD 17)

#if(WIN32)
#    set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -mwindows)
#endif()


add_subdirectory(Example2D)
add_subdirectory(Example3D)



