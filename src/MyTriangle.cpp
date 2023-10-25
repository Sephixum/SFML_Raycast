#include "MyTriangle.hpp"

MyTriangle::MyTriangle() : vertices_(sf::Triangles, 3) { Init(); }

void MyTriangle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();
  states.blendMode = sf::BlendAlpha;

  target.draw(vertices_, states);
}

auto MyTriangle::Init() -> void {
  vertices_[0].position = sf::Vector2f(1.f, 1.f);
  vertices_[0].color = sf::Color::Red;

  vertices_[1].position = sf::Vector2f(7.f, 4.5f);
  vertices_[1].color = sf::Color::Red;

  vertices_[2].position = sf::Vector2f(1.f, 8.f);
  vertices_[2].color = sf::Color::Red;

  setOrigin(Utils::MiddleOfShape(vertices_));
  // setPosition(kMap_width / 2.f, kMap_height / 2.f);
}
