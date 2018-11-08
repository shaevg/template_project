cmake_minimum_required(VERSION 3.10)

project(launcher)

set(LAUNCHER_VARIANT "regular" CACHE STRING
    "Somthing about launcher variants")

set(LAUNCHER_VARIANT_VALUES
  "regular;variant 1;variant 2")

set_property(CACHE LAUNCHER_VARIANT PROPERTY STRINGS ${LAUNCHER_VARIANT_VALUES})

set(LAUNCHER_DEFINE)

if (LAUNCHER_VARIANT STREQUAL "regular")
    set(LAUNCHER_DEFINE "_REGULAR_")
elseif (LAUNCHER_VARIANT STREQUAL "variant 1")
    set(LAUNCHER_DEFINE "_VARIANT_1_")
elseif (LAUNCHER_VARIANT STREQUAL "variant 2")
    set(LAUNCHER_DEFINE "_VARIANT_2_")
endif ()
add_definitions(-D${LAUNCHER_DEFINE})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} libA)
target_link_libraries(${PROJECT_NAME} libB)

include_directories(../)
