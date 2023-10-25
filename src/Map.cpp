#include "Map.hpp"

Tile::Tile() : tile(sf::Vector2f(kTile_width, kTile_width)) {}

Map::Map() { Init(); }

auto Map::Init() -> void {
  !texture_.create(kMap_width, kMap_height)
      ? std::cout << "\n============Map not created===========\n"
      : std::cout << "\n==============Map created=============\n";

  PopulateTiles();
}

auto Map::PopulateTiles() noexcept -> void {
  for (float i{0.1}; i < kMap_tile_in_height; ++i) {
    TilePtrVec temp_vec;
    temp_vec.reserve(kMap_tile_in_width);
    for (float j{0.1}; j < kMap_tile_in_width; ++j) {
      TilePtr temp_tile = std::make_shared<Tile>();

      temp_tile->tile.setFillColor(sf::Color::Black);
      temp_tile->tile.setOutlineThickness(1.0f);
      temp_tile->tile.setOutlineColor(sf::Color::White);
      temp_tile->tile.setPosition(
          sf::Vector2f(j * kTile_width, i * kTile_width));

      temp_vec.push_back(std::move(temp_tile));
    }
    map_tiles_.push_back(std::move(temp_vec));
  }
}

auto Map::Update(const Player &player) -> void {
  texture_.clear(sf::Color(255, 255, 255, 120));
  for (const auto &vector : map_tiles_) {
    for (const auto &e : vector) {
      texture_.draw(e->tile);
    }
  }
  texture_.draw(player);
  texture_.display();
}

auto Map::GetTexture() const noexcept -> sf::Texture {
  return texture_.getTexture();
}
