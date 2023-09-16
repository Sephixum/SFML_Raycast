#pragma once

#include "Player.hpp"

class Map : public sf::Drawable {
private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  sf::RectangleShape _tileSelector;
  sf::Vector2u _tileSelectorPos;

public:
  Map();
  void initMap();
  void update(Player &);
  void changeCellTypeAndColor(sf::Vector2i &);

  CELL tileMap[MAP_SIZE_WIDHT][MAP_SIZE_HEIGHT];
  CELL_TYPES currentSelectedCellType;
};
