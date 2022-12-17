cmake_minimum_required(VERSION 3.16)
project(lab3)

set(CMAKE_CXX_STANDARD 17)


file(GLOB_RECURSE SOURCES
        src/*.h
        src/*.cpp
        src/*.tcc
        src/*.hpp
        )

add_executable(lab3 ${SOURCES})
