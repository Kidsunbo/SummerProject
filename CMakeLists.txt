cmake_minimum_required(VERSION 3.14)
project(SummerProject)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
    set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -mwindows)
endif()

option(ENABLE_TEST "if enable test" ON)
option(ENABLE_EXAMPLE "if enable example" ON)

add_subdirectory(raster)

function(kie_add_executable name)
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name} PRIVATE raster)
    target_compile_definitions(${name} PUBLIC RESOURCE_PATH=\"${CMAKE_SOURCE_DIR}/resource\")
endfunction(kie_add_executable)

if(ENABLE_TEST)
    add_subdirectory(test)
endif()

if(ENABLE_EXAMPLE)
    add_subdirectory(example)
endif()



