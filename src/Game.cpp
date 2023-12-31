#include "Game.hpp"

Game::Game() {
  initVars();
  initWindow();
}

void Game::initVars() {
  _gameWindow = nullptr;
  _windowSettings.antialiasingLevel = 16;
  _videoMode.width = WINDOW_WIDTH;
  _videoMode.height = WINDOW_HEIGHT;
}

void Game::initWindow() {
  _gameWindow = std::make_unique<sf::RenderWindow>(
      _videoMode, "My sfml program", sf::Style::Default, _windowSettings);
  _gameWindow->setFramerateLimit(60);
  _gameWindow->setKeyRepeatEnabled(false);
}

const bool Game::running() const { return _gameWindow->isOpen(); }

void Game::pollEvents() {
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
          auto mousePOS = sf::Vector2i(_event.mouseButton.x / GRID_SIZE,
                                       _event.mouseButton.y / GRID_SIZE);
          _map.changeCellTypeAndColor(mousePOS);
        }
      }
    } break;
    default:
      break;
    }
  }
}

void Game::update() {
  _deltaTime = _deltaClock.restart().asSeconds();
  pollEvents();
  _player.Update(_deltaTime);
  _map.update(_player);
}

void Game::render() {
  _gameWindow->clear();
  _gameWindow->draw(_map);
  _player.DrawRays(*_gameWindow, _map.tileMap);
  _gameWindow->draw(_player);
  _gameWindow->display();
}
