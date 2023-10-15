cmake_minimum_required(VERSION 3.11)

project(
  raycasting
  VERSION 1.6.2
  DESCRIPTION "very efficient raycasting system"
  LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)
add_subdirectory(dependencies)

configure_file(version version.hpp)
