add_library(Game 
  Game.cpp
  Player.cpp
  MyTriangle.cpp
  Map.cpp
  MyFuncs.cpp
  )

target_include_directories(Game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
