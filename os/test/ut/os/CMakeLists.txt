cmake_minimum_required(VERSION 3.14)

get_filename_component(UNIT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(CONFIGURATION_PATH "cfg")
set(UNIT_SOURCE_PATH "../../../src")
set(EXECUTABLE_NAME "${UNIT_NAME}_ut_executable")
set(TEST_NAME "${UNIT_NAME}_test")

list(APPEND LOCAL_MOCK_SOURCES ${MOCK_SOURCES})
list(FILTER LOCAL_MOCK_SOURCES EXCLUDE REGEX ".*test/mock/${UNIT_NAME}")

include_directories(${CONFIGURATION_PATH})
FILE(GLOB_RECURSE CFG_SOURCES_C  "${CONFIGURATION_PATH}/*.c")

include_directories(${CONFIGURATION_PATH})
FILE(GLOB_RECURSE CFG_SOURCES_CPP  "${CONFIGURATION_PATH}/*.cpp")

set(SOURCES
    "${UNIT_SOURCE_PATH}/${UNIT_NAME}.c"
	${UNIT_TEST_SOURCE_WILDCARD}
    ${LOCAL_MOCK_SOURCES}
	${CFG_SOURCES_C}
	${CFG_SOURCES_CPP}
    )

add_executable(${EXECUTABLE_NAME} ${SOURCES})
target_link_libraries(${EXECUTABLE_NAME} gtest_main gmock_main)

include(GoogleTest)
gtest_add_tests(
	TARGET ${EXECUTABLE_NAME}
	EXTRA_ARGS --gtest_output=xml:${TEST_RESULTS_DIRECTORY}/googletest_${EXECUTABLE_NAME}.xml --gtest_filter=*
	)
