cmake_minimum_required(VERSION 3.10)

project(LilithTest)

# Lilith.h is in the parent directory
include_directories(${CMAKE_SOURCE_DIR}/..)

add_executable(lilith_test lilith_test.c)

# Link the math library
target_link_libraries(lilith_test m)