cmake_minimum_required(VERSION 3.10)

project(lilith)

add_library(lilith STATIC src/Lilith.c)

target_include_directories(lilith PUBLIC include)