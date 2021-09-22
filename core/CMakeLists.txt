cmake_minimum_required(VERSION 3.14)

FILE(GLOB_RECURSE unitTestDirs LIST_DIRECTORIES true ${unitTestDirectory})
list(FILTER unitTestDirs INCLUDE REGEX "^.*/ut/*.")

if(BUILD_TESTS)
    foreach(dir ${unitTestDirs})
        if(EXISTS "${dir}/CMakeLists.txt")
            add_subdirectory(${dir})
        endif()
    endforeach(dir)
else(BUILD_PROJECT)
    add_subdirectory(${sourceDirectory})
endif()
