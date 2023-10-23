#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <memory>

class Map {
private:
  sf::RenderTexture map_;

public:
  auto Draw(sf::Sprite &s) -> void;
  auto Init() -> void;
  Map();
};
