#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>

class MyTriangle : public sf::Drawable, public sf::Transformable {
private:
  void initTriangle();
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
  MyTriangle();
  sf::VertexArray vertices;

};
