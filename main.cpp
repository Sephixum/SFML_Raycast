#include "version.hpp"
#include <Game.hpp>
#include <iostream>

int main() {
  Game game;
  std::cout << "raycasting project version : " << raycasting_VERSION_MAJOR
            << "." << raycasting_VERSION_MINOR << "."
            << raycasting_VERSION_PATCH << '\n';
  while (game.running()) {
    game.update();
    game.render();
  }
  return 0;
}
