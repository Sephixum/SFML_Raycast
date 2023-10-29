cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

project(
  Raycasting_engine
  VERSION 0.1.0
  DESCRIPTION "Very efficient raycasting engine based DDA algorithm"
  LANGUAGES CXX)

add_subdirectory(dependencies)

add_executable(output)
target_sources(
  output
  PRIVATE src/main.cpp
          src/Engine.cpp
          src/Gui.cpp
          src/Textures.cpp
          src/Map.cpp
          src/Utils.cpp
          src/MyTriangle.cpp
          src/Player.cpp
          src/Ray.cpp)
target_include_directories(output PRIVATE ${PROJECT_BINARY_DIR}
                                          ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(output PRIVATE sfml-graphics sfml-system sfml-window
                                     ImGui-SFML)

configure_file(version version.hpp)
