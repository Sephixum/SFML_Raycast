#include "version.hpp"
#include <Game.hpp>
#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"

int main() {
  Game game;
  std::cout << "raycasting project version : "
            << Raycasting_engine_VERSION_MAJOR << "."
            << Raycasting_engine_VERSION_MINOR << "."
            << Raycasting_engine_VERSION_PATCH << '\n';
  while (game.running()) {
    game.update();
    game.render();
  }
  return 0;
}
