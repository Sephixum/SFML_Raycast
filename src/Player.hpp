#pragma once

#include <Globals.hpp>
#include <MyTrinagle.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cmath>

class Player : public sf::Drawable, public sf::Transformable {
private:
  void initPlayer();

  float _angle;
  sf::Vector2f _spritePOS;
  sf::Texture _texture;
  float _visionDensity = 900;

protected:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
  Player();
  void Update(float);
  void DrawRays(sf::RenderWindow &, Cell[MAP_SIZE_WIDHT][MAP_SIZE_HEIGHT]);
  void DrawRay(sf::RenderWindow &, Cell[MAP_SIZE_WIDHT][MAP_SIZE_HEIGHT], float,
               unsigned short);
  void RenderWorld(sf::RenderWindow &, float, float, unsigned short, sf::Color, float);

  MyTriangle sprite;
};
