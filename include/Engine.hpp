#pragma once

#include "Globals.hpp"
#include "Gui.hpp"
#include "Map.hpp"
#include "MyTriangle.hpp"
#include "Player.hpp"
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
  sf::Event event_;
  sf::Clock delta_clock_;

  Gui gui_;
  Map mini_map_;
  Player mini_map_sprite_;
  Textures textures_;

public:
  Engine();
  Engine(Engine &&) = delete;
  Engine(const Engine &) = delete;
  Engine &operator=(Engine &&) = delete;
  Engine &operator=(const Engine &) = delete;
  ~Engine();

  auto PollEvents() -> void;
  auto Update() noexcept -> void;
  auto Render() const noexcept -> void;
  auto Run() noexcept -> void;
};
