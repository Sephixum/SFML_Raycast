cmake_minimum_required(VERSION 3.11)

project(
  Raycasting_engine
  VERSION 1.6.2
  DESCRIPTION "very efficient raycasting system"
  LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(raycasting)
target_sources(
  raycasting PRIVATE src/main.cpp src/Game.cpp src/Map.cpp src/MyFuncs.cpp
                     src/MyTriangle.cpp src/Player.cpp)
target_include_directories(
  raycasting PRIVATE ${PROJECT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Dependency management
add_subdirectory(dependencies)

target_link_libraries(raycasting PRIVATE sfml-graphics sfml-system sfml-window ImGui-SFML)

# Copy textures into binary directory
set(TEXTURES_DIR ${CMAKE_SOURCE_DIR}/textures)
add_custom_command(
  TARGET raycasting
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${TEXTURES_DIR}
          $<TARGET_FILE_DIR:raycasting>/textures)

# Handle dll files and copy them in bin direcotry
if(WIN32)
  message("Copying runtime dlls into binary directory...")
  add_custom_command(
    TARGET raycasting
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:raycasting>
            $<TARGET_FILE_DIR:raycasting>
    COMMAND_EXPAND_LISTS)
endif()

configure_file(version version.hpp)
