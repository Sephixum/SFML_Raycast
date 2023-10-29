#pragma once

#include "Globals.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <memory>

enum TileType { empty, wall };

struct Tile {
  Tile();
  sf::RectangleShape tile;
  TileType type;
  auto SetType(TileType tile_type) -> void;
};

using TilePtr = std::shared_ptr<Tile>;
using TilePtrVec = std::vector<TilePtr>;

namespace Utils {
auto MiddleOfShape(const sf::VertexArray &) -> sf::Vector2f;
auto DegreeToRads(float deg) -> float;
auto RadsToDegree(float rad) -> float;
auto Normalize(const sf::Vector2f &vector) -> sf::Vector2f;
} // namespace Utils
