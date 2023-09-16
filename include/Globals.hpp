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

constexpr float PERPENDICULAR_LINE_SCALE = 15.f;

enum CELL_TYPES {
  Empty = 0,
  BlueStone,
  ColorStone,
  Eagle,
  GreyStone,
  Mossy,
  PurpleBrick,
  RedBrick,
  Wood
};

struct CELL {
  CELL_TYPES type;
  sf::RectangleShape tile;
};
