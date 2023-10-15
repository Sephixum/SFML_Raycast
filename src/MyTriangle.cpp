#include "MyTriangle.hpp"

MyTriangle::MyTriangle() : vertices(sf::PrimitiveType::Triangles, 3) { initTriangle(); }

void MyTriangle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();
  states.blendMode = sf::BlendAlpha;

  target.draw(vertices, states);
}

void MyTriangle::initTriangle() {
  vertices[0].position = sf::Vector2f(10.f, 10.f);
  vertices[0].color = sf::Color::White;

  vertices[1].position = sf::Vector2f(20.f, 13.5f);
  vertices[1].color = sf::Color::White;

  vertices[2].position = sf::Vector2f(10.f, 17.f);
  vertices[2].color = sf::Color::White;
}
