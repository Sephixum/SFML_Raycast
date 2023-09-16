#pragma once

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>

namespace fn {
sf::Vector2f normalize(const sf::Vector2f &);
float degToRad(float);
float radToDeg(float);
sf::Vector2f averageOfVertexArray(const sf::VertexArray &);
} // namespace fn
