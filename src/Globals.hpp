#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

constexpr float PI = 3.141592;

constexpr int FOV = 66;
constexpr float SPEED = 100.f;

constexpr int WINDOW_WIDTH{1800};
constexpr int WINDOW_HEIGHT{625};

constexpr int MAP_SIZE_WIDHT = 36;
constexpr int MAP_SIZE_HEIGHT = 25;
constexpr float GRID_SIZE = 25.f;

enum CellTypes { Empty, Wall };

struct Cell {
  CellTypes type;
  sf::RectangleShape tile;
};
