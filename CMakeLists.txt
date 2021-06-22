cmake_minimum_required(VERSION 3.14)

FILE(GLOB_RECURSE modulesDirs LIST_DIRECTORIES true ${CMAKE_CURRENT_SOURCE_DIR})
list(FILTER modulesDirs INCLUDE REGEX "${CMAKE_CURRENT_SOURCE_DIR}/[^/]*$")

foreach(dir ${modulesDirs})
    if(EXISTS "${dir}/CMakeLists.txt")
        add_subdirectory(${dir})
    endif()
endforeach(dir)