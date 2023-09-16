cmake_minimum_required(VERSION 3.11)

project(raycasting 
        VERSION 1.6.2
        DESCRIPTION "very efficient raycasting system"
        LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SFML COMPONENTS graphics system window CONFIG REQUIRED)

set(TEXTURES_DIR ${CMAKE_SOURCE_DIR}/textures)

add_executable(raycasting)

target_sources(raycasting PRIVATE
               src/main.cpp
               src/Game.cpp
               src/Map.cpp
               src/MyFuncs.cpp
               src/MyTriangle.cpp
               src/Player.cpp
               )

target_include_directories(raycasting PRIVATE 
                           ${PROJECT_BINARY_DIR}
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
                           )

target_link_libraries(raycasting PRIVATE
                      sfml-graphics
                      sfml-system
                      sfml-window
                      )

configure_file(version version.hpp)