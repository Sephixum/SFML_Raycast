#pragma once

#include "Globals.hpp"
#include "Gui.hpp"
#include "Map.hpp"
#include "Textures.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <memory>

class Engine {
private:
  auto InitWindow() noexcept -> void;
  auto InitVariables() noexcept -> void;

  std::unique_ptr<sf::RenderWindow> window_;
  Map mini_map_;
  sf::Event event_;
  sf::Clock delta_clock_;
  Gui gui_;

  Textures textures_;
  sf::Sprite sprite;

public:
  Engine();
  Engine(Engine &&) = delete;
  Engine(const Engine &) = delete;
  Engine &operator=(Engine &&) = delete;
  Engine &operator=(const Engine &) = delete;
  ~Engine();

  auto PollEvents() -> void;
  auto Update() noexcept -> void;
  auto Render() noexcept -> void;
  auto Run() noexcept -> void;
};
