cmake_minimum_required(VERSION 3.10)

project(libA)

set(LIB_A_SOURCES liba.cpp liba.h)

add_library(${PROJECT_NAME} STATIC ${LIB_A_SOURCES})
