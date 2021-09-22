cmake_minimum_required(VERSION 3.14)

get_filename_component(unitName ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(configurationPath "cfg")
set(unitSourcePath "../../../src")
set(executableName "${unitName}_ut_executable")
set(testName "${unitName}_test")

list(APPEND localMockSources ${mockSources})
list(FILTER localMockSources EXCLUDE REGEX ".*test/mock/${unitName}")

include_directories(${configurationPath})
FILE(GLOB_RECURSE cfgSources  "${configurationPath}/*.c")

include_directories(${configurationPath})
FILE(GLOB_RECURSE cfgSourcesCpp  "${configurationPath}/*.cpp")

set(SOURCES
    "${unitSourcePath}/${unitName}.c"
    ${unitTestSource}
    ${localMockSources}
	${cfgSources}
	${cfgSourcesCpp}
    )

add_executable(${executableName} ${SOURCES})
target_link_libraries(${executableName} gtest_main gmock_main)

include(GoogleTest)
gtest_add_tests(
	TARGET ${executableName}
	EXTRA_ARGS --gtest_output=xml:${cosmos}/generated/build/tests/results/googletest_${executableName}.xml
	)
