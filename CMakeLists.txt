cmake_minimum_required(VERSION 2.8)

project(apue-code C)

set(AC_WORKSPACE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(AC_SOURCE_DIR ${AC_WORKSPACE_DIR}/src)
set(AC_INCLUDE_DIR ${AC_WORKSPACE_DIR}/includes)
set(EXECUTABLE_OUTPUT_PATH ${AC_WORKSPACE_DIR}/cmake-build/bin)

include_directories(BEFORE ${AC_INCLUDE_DIR})

add_subdirectory(${AC_SOURCE_DIR})


