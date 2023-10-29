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

class Map {
private:
  auto PopulateTiles() noexcept -> void;
  auto HandleInput() const noexcept -> void;

  sf::RenderTexture texture_;
  std::vector<TilePtrVec> map_tiles_;

public:
  Map();
  auto Init() -> void;
  auto Update() -> void;
  auto GetTexture() const noexcept -> sf::Texture;
  auto SpriteUpdate(float dt) -> void;
  Player sprite_;
};
