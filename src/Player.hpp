#pragma once

#include <Globals.hpp>
#include <MyTrinagle.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
#include <memory>
#include <vector>

class Player : public sf::Drawable, public sf::Transformable {
private:
  void initPlayer();

  float _angle;
  sf::Vector2f _spritePOS;
  float _visionDensity = 900;
  std::vector<sf::Texture> _textures;
  sf::Texture *_selectedTexture;

protected:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
  Player();
  ~Player();
  void Update(float);
  void DrawRays(sf::RenderWindow &, CELL[MAP_SIZE_WIDHT][MAP_SIZE_HEIGHT]);
  void DrawRay(sf::RenderWindow &, CELL[MAP_SIZE_WIDHT][MAP_SIZE_HEIGHT], float,
               unsigned short);
  void RenderWorld(sf::RenderWindow &, float, float, int, sf::Color, float,
                   CELL_TYPES &);

  MyTriangle sprite;
};
