cmake_minimum_required(VERSION 3.14)

if(NOT TARGET painter)
    add_subdirectory(../Painter ../Painter3D/Painter)
endif()

aux_source_directory(. SOURCE)
add_library(painter3d ${SOURCE})

target_include_directories(painter3d PUBLIC ../Painter)
target_link_libraries(painter3d PUBLIC painter)



