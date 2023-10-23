#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <filesystem>
#include <iostream>
#include <memory>
#include <vector>

class Textures {
public:
  Textures() = default;
  // Textures(Textures &&) = delete;
  // Textures(const Textures &) = delete;
  // Textures &operator=(Textures &&) = delete;
  // Textures &operator=(const Textures &) = delete;
  // ~Textures();
  auto Init() -> void;

  std::vector<sf::Texture> textures_vector;
  sf::Texture *selected_texture;
};
