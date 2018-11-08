cmake_minimum_required(VERSION 3.10)

project(template_project)

add_subdirectory(launcher)
add_subdirectory(libA)
add_subdirectory(libB)

enable_testing()
add_subdirectory(tests)
