#include <Map.hpp>

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  for (int i{0}; i < MAP_SIZE_WIDHT; i++) {
    for (int j{0}; j < MAP_SIZE_HEIGHT; j++) {
      target.draw(tileMap[i][j].tile, states);
    }
  }
  target.draw(_tileSelector, states);
}

Map::Map() { initMap(); }

void Map::initMap() {
  _tileSelector.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
  _tileSelector.setPosition(sf::Vector2f(GRID_SIZE, GRID_SIZE));
  _tileSelector.setFillColor(sf::Color::Black);
  _tileSelector.setOutlineThickness(1.f);
  _tileSelector.setOutlineColor(sf::Color::Red);

  currentSelectedCellType = CELL_TYPES::RedBrick;

  for (int i{0}; i < MAP_SIZE_WIDHT; i++) {
    for (int j{0}; j < MAP_SIZE_HEIGHT; j++) {
      tileMap[i][j].tile.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
      tileMap[i][j].tile.setOutlineThickness(1.f);
      if (i == 0 || i == MAP_SIZE_WIDHT - 1) {
        tileMap[i][j].type = CELL_TYPES::RedBrick;
        tileMap[i][j].tile.setFillColor(sf::Color::Black);
        tileMap[i][j].tile.setOutlineColor(sf::Color::White);
      } else if (j == 0 || j == MAP_SIZE_HEIGHT - 1) {
        tileMap[i][j].type = CELL_TYPES::RedBrick;
        tileMap[i][j].tile.setFillColor(sf::Color::Black);
        tileMap[i][j].tile.setOutlineColor(sf::Color::White);
      } else {
        tileMap[i][j].type = CELL_TYPES::Empty;
        tileMap[i][j].tile.setFillColor(sf::Color(255, 255, 255, 120));
        tileMap[i][j].tile.setOutlineColor(sf::Color::Black);
      }
      tileMap[i][j].tile.setPosition(i * GRID_SIZE, j * GRID_SIZE);
    }
  }
}

void Map::update(Player &player) {
  sf::Vector2u playerPosGrid;
  auto playerPos = player.sprite.getPosition();
  if (playerPos.x >= 0.f) {
    playerPosGrid.x = playerPos.x / GRID_SIZE;
  }
  if (playerPos.y >= 0.f) {
    playerPosGrid.y = playerPos.y / GRID_SIZE;
  }
  _tileSelector.setPosition(playerPosGrid.x * GRID_SIZE,
                           playerPosGrid.y * GRID_SIZE);
}

void Map::changeCellTypeAndColor(sf::Vector2i &position) {
  if (tileMap[position.x][position.y].type != CELL_TYPES::Empty) {
    tileMap[position.x][position.y].tile.setFillColor(
        sf::Color(255, 255, 255, 120));
    tileMap[position.x][position.y].type = CELL_TYPES::Empty;
  } else if (tileMap[position.x][position.y].type == CELL_TYPES::Empty) {
    switch (currentSelectedCellType) {
    case BlueStone: {
      tileMap[position.x][position.y].tile.setFillColor(
          sf::Color(0, 84, 255, 255));
      tileMap[position.x][position.y].type = currentSelectedCellType;
    } break;
    case ColorStone: {
      tileMap[position.x][position.y].tile.setFillColor(
          sf::Color(72, 56, 24, 255));
      tileMap[position.x][position.y].type = currentSelectedCellType;
    } break;
    case Eagle: {
      tileMap[position.x][position.y].tile.setFillColor(
          sf::Color(80, 0, 80, 255));
      tileMap[position.x][position.y].type = currentSelectedCellType;
    } break;
    case GreyStone: {
      tileMap[position.x][position.y].tile.setFillColor(
          sf::Color(0, 97, 83, 255));
      tileMap[position.x][position.y].type = currentSelectedCellType;
    } break;
    case Mossy: {
      tileMap[position.x][position.y].tile.setFillColor(
          sf::Color(255, 0, 39, 255));
      tileMap[position.x][position.y].type = currentSelectedCellType;
    } break;
    case PurpleBrick: {
      tileMap[position.x][position.y].tile.setFillColor(
          sf::Color(255, 145, 245, 255));
      tileMap[position.x][position.y].type = currentSelectedCellType;
    } break;
    case RedBrick: {
      tileMap[position.x][position.y].tile.setFillColor(
          sf::Color(245, 255, 0, 255));
      tileMap[position.x][position.y].type = currentSelectedCellType;
    } break;
    case Wood: {
      tileMap[position.x][position.y].tile.setFillColor(
          sf::Color(103, 0, 0, 255));
      tileMap[position.x][position.y].type = currentSelectedCellType;
    } break;
    default:
      break;
    }
  }
}
