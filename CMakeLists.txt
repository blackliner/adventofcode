cmake_minimum_required(VERSION 3.18)

include(cmake/launcher.cmake)

project(
  advent_of_code
  VERSION 1.0.0
  LANGUAGES CXX)

include(cmake/utils.cmake)
include(cmake/testing.cmake)

find_package(Catch2 2.13.3 REQUIRED)

add_subdirectory(2020)
