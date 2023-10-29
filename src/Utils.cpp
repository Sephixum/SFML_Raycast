#include "Utils.hpp"

auto Tile::SetType(TileType tile_type) -> void { type = tile_type; }

auto Utils::MiddleOfShape(const sf::VertexArray &vertecies) -> sf::Vector2f {
  auto sum_of_x = 0.f;
  auto sum_of_y = 0.f;
  auto numberOfVertexIndeces = vertecies.getVertexCount();
  for (unsigned short i{0}; i < numberOfVertexIndeces; i++) {
    sum_of_x += vertecies[i].position.x;
    sum_of_y += vertecies[i].position.y;
  }
  return sf::Vector2f(sum_of_x / numberOfVertexIndeces,
                      sum_of_y / numberOfVertexIndeces);
}

auto Utils::DegreeToRads(float deg) -> float { return deg * kPi / 180.f; }

auto Utils::RadsToDegree(float rad) -> float { return rad * 180.f / kPi; }

auto Utils::Normalize(const sf::Vector2f &vector) -> sf::Vector2f {
  auto normalized_vector = vector;

  float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
  if (length != 0.0f) {
    normalized_vector /= length;
  }
  return normalized_vector;
}
