#include "vesion.hpp"
#include <Game.hpp>
#include <iostream>

int main() {
  Game game;
  while (game.running()) {
    game.update();
    game.render();
  }
  return 0;
}
