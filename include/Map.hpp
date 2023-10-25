#pragma once

#include "Globals.hpp"
#include "MyTriangle.hpp"
#include "Player.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <memory>
#include <vector>

enum TileType { empty, wall };

struct Tile {
  Tile();
  sf::RectangleShape tile;
  TileType type;
};

using TilePtr = std::shared_ptr<Tile>;
using TilePtrVec = std::vector<TilePtr>;

class Map {
private:
  auto PopulateTiles() noexcept -> void;
  auto HandleInput() const noexcept -> void;

  sf::RenderTexture texture_;
  std::vector<TilePtrVec> map_tiles_;

public:
  auto Init() -> void;
  auto Update(const Player &player) -> void;
  auto GetTexture() const noexcept -> sf::Texture;
  Map();
};
