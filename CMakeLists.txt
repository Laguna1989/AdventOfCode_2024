cmake_minimum_required(VERSION 3.16)
project(AdventOfCode2024 LANGUAGES CXX)

set(FETCHCONTENT_UPDATES_DISCONNECTED ON)

set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CXX_STANDARD 23)

add_subdirectory(ext)
add_subdirectory(day01)
add_subdirectory(day02)
