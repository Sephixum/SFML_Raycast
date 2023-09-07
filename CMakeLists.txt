cmake_minimum_required(VERSION 3.11)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project(raycasting)

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

# add_custom_command( TARGET raycasting
#                    POST_BUILD
#                    COMMAND ${CMAKE_COMMAND}
#                    -E copy_directory ${TEXTURES_DIR}
#                    $<TARGET_FILE_DIR:raycasting>/pics)
