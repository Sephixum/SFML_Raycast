#pragma once

#include "Globals.hpp"

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace Utils {
auto MiddleOfShape(const sf::VertexArray &) -> sf::Vector2f;
auto DegreeToRads(float deg) -> float;
auto RadsToDegree(float rad) -> float;
auto Normalize(const sf::Vector2f &vector) -> sf::Vector2f;
} // namespace Utils
