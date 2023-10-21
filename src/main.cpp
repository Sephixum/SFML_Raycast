#include "Engine.hpp"
#include "version.hpp"

#include <iostream>

auto main() -> int {
  std::cout << "Welcome to Raycasting_engine "
            << Raycasting_engine_VERSION_MAJOR << "."
            << Raycasting_engine_VERSION_MINOR << "."
            << Raycasting_engine_VERSION_PATCH << '\n';

  Engine engine;
  engine.Run();

  return EXIT_SUCCESS;
}
