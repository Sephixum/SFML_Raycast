add_library(Game 
  Game.cpp
  Map.cpp
  MyFuncs.cpp
  MyTriangle.cpp
  Player.cpp
  )

target_include_directories(Game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
