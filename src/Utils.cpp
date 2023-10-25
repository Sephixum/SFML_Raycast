#include "Utils.hpp"

sf::Vector2f Utils::MiddleOfShape(const sf::VertexArray &vertecies) {
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
