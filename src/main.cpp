#include "version.hpp"
#include <Game.hpp>
#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"

int main() {
  Engine engine;
  std::cout << "Raycasting engine version : "
            << Raycasting_engine_VERSION_MAJOR << "."
            << Raycasting_engine_VERSION_MINOR << "."
            << Raycasting_engine_VERSION_PATCH << '\n';
  while (engine.running()) {
    engine.update();
    engine.render();
  }
  return 0;
}
