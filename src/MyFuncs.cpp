#include <MyFuncs.hpp>
#include <cmath>

sf::Vector2f fn::normalize(const sf::Vector2f &vector) {
  auto normalized = vector;
  float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
  if (length != 0.0f) {
    normalized /= length;
  }
  return normalized;
}

float fn::degToRad(float degree) { return degree * 3.14159 / 180.f; }

float fn::radToDeg(float rad) { return rad * 180.f / 3.14159; }

sf::Vector2f fn::averageOfVertexArray(const sf::VertexArray &vertecies) {
  auto sumOfxs = 0.f;
  auto sumOfys = 0.f;
  auto numberOfVertexIndeces = vertecies.getVertexCount();
  for (unsigned short i{0}; i < numberOfVertexIndeces; i++) {
    sumOfxs += vertecies[i].position.x;
    sumOfys += vertecies[i].position.y;
  }
  return sf::Vector2f(sumOfxs / numberOfVertexIndeces,
                      sumOfys / numberOfVertexIndeces);
}
