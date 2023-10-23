#include "Map.hpp"

Map::Map() { Init(); }

auto Map::Init() -> void {
  if (!map_.create(500, 500)) {
    std::cout << "\n============Map not created===========\n";
  } else {
    std::cout << "\n==============Map created=============\n";
  }
}

auto Map::Draw(sf::Sprite &s) -> void {
  map_.clear(sf::Color::White);
  map_.draw(s);
  map_.display();
}
