add_executable(raycasting)

target_sources(raycasting PRIVATE main.cpp Game.cpp Map.cpp MyFuncs.cpp
                                  MyTriangle.cpp Player.cpp)

target_include_directories(
  raycasting PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(raycasting PRIVATE sfml-graphics sfml-system sfml-window)

set(TEXTURES_DIR ${CMAKE_SOURCE_DIR}/textures)

add_custom_command(
  TARGET raycasting
  POST_BUILD
  COMMAND
    ${CMAKE_COMMAND} -E copy_directory ${TEXTURES_DIR}
    $<TARGET_FILE_DIR:raycasting>/textures)
