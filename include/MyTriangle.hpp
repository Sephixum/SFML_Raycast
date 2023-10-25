#pragma once

#include "Globals.hpp"
#include "Utils.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>

class MyTriangle : public sf::Drawable, public sf::Transformable {
private:
  auto draw(sf::RenderTarget &target, sf::RenderStates states) const
      -> void override;

  sf::VertexArray vertices_;

public:
  MyTriangle();
  auto Init() -> void;
};
