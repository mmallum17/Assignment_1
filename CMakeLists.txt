cmake_minimum_required(VERSION 3.5)
project(Assignment_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES quiz.c)
add_executable(Assignment_1 ${SOURCE_FILES})