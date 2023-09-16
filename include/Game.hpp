#pragma once

#include "Map.hpp"
#include <SFML/Window/Event.hpp>
#include <memory>

class Game {
private:
  void initVars();
  void initWindow();

  std::unique_ptr<sf::RenderWindow> _gameWindow;
  sf::VideoMode _videoMode;
  sf::Event _event;
  sf::ContextSettings _windowSettings;

  sf::Clock _deltaClock;
  float _deltaTime;

  Player _player;
  Map _map;

public:
  Game();
  const bool running() const;
  void pollEvents();
  void update();
  void render();
  void run();
};
