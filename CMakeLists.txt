#include(FetchContent)
cmake_minimum_required(VERSION 3.11)

project(
  Raycasting_Engine
  VERSION 1.6.2
  DESCRIPTION "very efficient raycasting system"
  LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(TEXTURES_DIR ${CMAKE_SOURCE_DIR}/textures)

configure_file(version version.hpp)

#add_subdirectory(src)
add_executable(raycasting)

target_sources(raycasting PRIVATE
        src/main.cpp
        src/Game.cpp
        src/Map.cpp
        src/MyFuncs.cpp
        src/MyTriangle.cpp
        src/Player.cpp)

target_include_directories(
        raycasting PRIVATE include)

target_link_libraries(raycasting PRIVATE sfml-graphics sfml-system sfml-window)


add_custom_command(
        TARGET raycasting
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_directory ${TEXTURES_DIR}
        $<TARGET_FILE_DIR:raycasting>/textures)

if(WIN32)
    add_custom_command(
            TARGET raycasting POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:raycasting> $<TARGET_FILE_DIR:raycasting>
            COMMAND_EXPAND_LISTS)
endif()

add_subdirectory(dependencies)
