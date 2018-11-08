cmake_minimum_required(VERSION 3.10)

project(libB)

set(LIB_B_SOURCES libb.cpp libb.h)

add_library(${PROJECT_NAME} STATIC ${LIB_B_SOURCES})
