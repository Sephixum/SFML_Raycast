#pragma once

#include "Map.hpp"
#include <SFML/Window/Event.hpp>
#include <memory>
#include "imgui.h"
#include "imgui-SFML.h"

class Engine {
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
  Engine();
  Engine(Engine &&other) = delete;
  Engine(const Engine &other) = delete;
  Engine &operator=(Engine &&other) = delete;
  Engine &operator=(const Engine &other) = delete;
  ~Engine();

  bool running() const;
  void pollEvents();
  void update();
  void render();
};