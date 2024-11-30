# CMakeLists.txt for tstGPS
# 28-11-2024 by madpl

cmake_minimum_required(VERSION 3.30)
project(tstGPS)
add_definitions(-Os -march=native -std=c++23)

file(GLOB_RECURSE SOURCE ./source/*)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE})
