cmake_minimum_required(VERSION 3.11)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project(raycasting 
        VERSION 1.6.2
        LANGUAGES CXX)

set(TEXTURES_DIR ${CMAKE_SOURCE_DIR}/textures)

add_executable(raycasting main.cpp)

add_subdirectory(src)

target_compile_features(raycasting PRIVATE
                        cxx_std_17)

target_link_libraries(raycasting PRIVATE
                      sfml-graphics
                      sfml-system
                      sfml-window
                      Game
                      )
configure_file(version version.hpp)

target_include_directories(raycasting PRIVATE ${PROJECT_BINARY_DIR})
