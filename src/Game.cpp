#include "Game.hpp"

Engine::Engine() {
  initVars();
  initWindow();
}

void Engine::initVars() {
  _gameWindow = nullptr;
  _windowSettings.antialiasingLevel = 16;
  _videoMode.width = WINDOW_WIDTH;
  _videoMode.height = WINDOW_HEIGHT;
}

void Engine::initWindow() {
  _gameWindow = std::make_unique<sf::RenderWindow>(
      _videoMode, "My sfml program", sf::Style::Default, _windowSettings);
  _gameWindow->setFramerateLimit(60);
  _gameWindow->setKeyRepeatEnabled(false);
}

bool Engine::running() const { return _gameWindow->isOpen(); }

void Engine::pollEvents() {
  while (_gameWindow->pollEvent(_event)) {
    switch (_event.type) {
    case sf::Event::Closed: {
      _gameWindow->close();
    } break;
    case sf::Event::KeyPressed: {
      unsigned indexOfTexture = _event.key.code - sf::Keyboard::Num1;
      if (indexOfTexture <= 8) {
        _map.currentSelectedCellType =
            static_cast<CELL_TYPES>(indexOfTexture + 1);
      }
    } break;
    case sf::Event::MouseButtonPressed: {
      if (_event.mouseButton.button == sf::Mouse::Left) {
        if (_event.mouseButton.x < (WINDOW_WIDTH / 2)) {
          auto mousePOS = sf::Vector2i(static_cast<int>(_event.mouseButton.x / GRID_SIZE),
                                       static_cast<int>(_event.mouseButton.y / GRID_SIZE));
          _map.changeCellTypeAndColor(mousePOS);
        }
      }
    } break;
    default:
      break;
    }
  }
}

void Engine::update() {
  _deltaTime = _deltaClock.restart().asSeconds();
  pollEvents();
  _player.Update(_deltaTime);
  _map.update(_player);
}

void Engine::render() {
  _gameWindow->clear();
  _gameWindow->draw(_map);
  _player.DrawRays(*_gameWindow, _map.tileMap);
  _gameWindow->draw(_player);
  _gameWindow->display();
}
