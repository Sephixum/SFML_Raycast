#pragma once

#include <Globals.hpp>
#include <Player.hpp>
#include <vector>

class Map : public sf::Drawable {
private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
  Map();
  void initMap();
  void update(Player &);
  void changeCellTypeAndColor(sf::Vector2i &);

  CELL tileMap[MAP_SIZE_WIDHT][MAP_SIZE_HEIGHT];
  CELL_TYPES currentSelectedCellType;
  sf::RectangleShape tileSelector;
  sf::Vector2u tileSelectorPos;
};
