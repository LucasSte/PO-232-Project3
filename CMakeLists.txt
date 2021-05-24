cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

file(GLOB curDir "*.cpp" "*.h")

add_executable(untitled ${curDir})
