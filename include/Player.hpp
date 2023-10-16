#pragma once

#include "Globals.hpp"
#include "MyTriangle.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cmath>

class Player : public sf::Drawable {
private:
  void initPlayer();
  void DrawRay(sf::RenderWindow &, CELL[MAP_SIZE_WIDHT][MAP_SIZE_HEIGHT], float,
               unsigned short);
  void setUpWallStripe(sf::VertexArray &, const int, const float, const float);

  float _angle;
  sf::Vector2f _spritePOS;
  float _visionDensity = 900;
  std::vector<sf::Texture> _textures;
  sf::Texture *_selectedTexture;

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
  Player();
  ~Player() override;
  void Update(float &);
  void DrawRays(sf::RenderWindow &, CELL[MAP_SIZE_WIDHT][MAP_SIZE_HEIGHT]);
  void RenderWorld(sf::RenderWindow &, float, float, int, float, CELL_TYPES);

  MyTriangle sprite;
};
