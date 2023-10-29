#pragma once

#include "Globals.hpp"
#include "MyTriangle.hpp"
#include "Ray.hpp"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <vector>


struct Player : public sf::Drawable {
private:
  auto draw(sf::RenderTarget &target, sf::RenderStates states) const
      -> void override;

public:
  Player() = default;
  explicit Player(sf::Vector2f &initial_position);
  explicit Player(float initial_position_x, float initial_postion_y);

  auto Init() noexcept -> void;
  auto GetPosition() -> sf::Vector2f;
  auto SetPosition(sf::Vector2f &new_position) -> void;
  auto SetPosition(float new_position_x, float new_position_y) -> void;
  auto Update(float dt) -> void;
  auto CastRays(const std::vector<TilePtrVec> &tiles) -> void;

  MyTriangle sprite;
  std::vector<Ray> rays;
  float player_angle;
  int vision_density;
};
