cmake_minimum_required(VERSION 3.10)

project(tests)

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(../)

add_definitions(-DBOOST_TEST_DYN_LINK)

set(TEST_SOURCES
    test.cpp
    liba_test.cpp
    libb_test.cpp
)

add_executable(${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(${PROJECT_NAME} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(${PROJECT_NAME} libA)
target_link_libraries(${PROJECT_NAME} libB)

add_test(NAME test_lib_A COMMAND ${PROJECT_NAME} --run=libA_test_suite)
add_test(NAME test_lib_B COMMAND ${PROJECT_NAME} --run=libB_test_suite)
