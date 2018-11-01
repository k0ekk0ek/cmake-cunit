#
# Simple demo project to show how easy integration between the CUnit test
# framework and the CUnit CMake module is supposed to work.
#
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/Modules")

project(demo C)
cmake_minimum_required(VERSION 3.6)

include(CUnit)
include(CTest)

add_cunit_executable(demo src/foo.c src/bar.c)

