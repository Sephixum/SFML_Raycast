#pragma once

#include "Globals.hpp"
#include "Utils.hpp"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

class Ray : public sf::Drawable {
private:
  auto draw(sf::RenderTarget &target, sf::RenderStates states) const
      -> void override;

  sf::VertexArray stripe_;

public:
  Ray();
  explicit Ray(const sf::Vector2f begin, const sf::Vector2f end);

  auto SetPosition(const sf::Vector2f begin, const sf::Vector2f end) -> void;
  auto SetColor(const sf::Color begin_color, const sf::Color end_color) -> void;
  auto SetTexCoord(const sf::Vector2f begin_coords,
                   const sf::Vector2f end_coords) -> void;
  /*
   * returns ...
   * Desc : Perform DDA
   */
  auto Cast(const sf::Vector2f begin_position, float angle_of_ray,
            const std::vector<TilePtrVec> &tiles) -> Ray;
};
