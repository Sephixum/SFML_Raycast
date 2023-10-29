#pragma once

#include "Textures.hpp"

#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

struct Gui {
  Gui() = default;
  auto Init(sf::RenderWindow &window) const noexcept -> void;
  auto Update(sf::RenderWindow &window, sf::Time time_elapsed,
              Textures &textures_vec, int *vision_density) noexcept -> void;
  auto ProcessEvent(sf::Event event) const noexcept -> void;
  auto Render(sf::RenderWindow &window) const noexcept -> void;
  auto ShutDown() const noexcept -> void;

  auto DrawTextures(Textures &textures) -> void;
};
