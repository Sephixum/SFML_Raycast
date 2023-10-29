#include "Player.hpp"
#include "Globals.hpp"
#include "Ray.hpp"
#include <vector>

Player::Player(sf::Vector2f &initial_position)
    : player_angle(45.f), vision_density(kWindow_width) {
  sprite.setPosition(initial_position);
}

Player::Player(float initial_position_x, float initial_postion_y)
    : player_angle(45.f), vision_density(kWindow_width) {
  sprite.setPosition(sf::Vector2f(initial_position_x, initial_postion_y));
}

auto Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
    -> void {
  target.draw(sprite, states);
}

auto Player::GetPosition() -> sf::Vector2f { return sprite.getPosition(); }

auto Player::SetPosition(sf::Vector2f &new_position) -> void {
  sprite.setPosition(new_position);
}

auto Player::SetPosition(float new_position_x, float new_position_y) -> void {
  sprite.setPosition(sf::Vector2f(new_position_x, new_position_y));
}

auto Player::Update(float dt) -> void {
  auto player_angle_in_rads = Utils::DegreeToRads(player_angle);

  sf::Vector2f horizontal_difference(
      kPlayer_speed * dt * std::cos(player_angle_in_rads),
      kPlayer_speed * dt * std::sin(player_angle_in_rads));
  sf::Vector2f vertical_difference(
      kPlayer_speed * dt * std::cos(player_angle_in_rads + kPi / 2),
      kPlayer_speed * dt * std::sin(player_angle_in_rads + kPi / 2));

  auto new_sprite_position = sprite.getPosition();

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    new_sprite_position += horizontal_difference;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    new_sprite_position -= horizontal_difference;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    new_sprite_position -= vertical_difference;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    new_sprite_position += vertical_difference;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
    player_angle -= kPlayer_speed * dt * 2;
    if (player_angle < 0) {
      player_angle += 360;
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
    player_angle += kPlayer_speed * dt * 2;
    if (player_angle > 360) {
      player_angle -= 360;
    }
  }

  sprite.setPosition(new_sprite_position);
  sprite.setRotation(player_angle);
}

auto Player::CastRays(const std::vector<TilePtrVec> &tiles) -> void {
  rays.clear();

  float half_of_fov = kFov /2.f;
  float delta_ray_deg = kFov / vision_density;
  float current_ray_angle = player_angle - half_of_fov;
  float ray_end_deg = player_angle + half_of_fov;

  int current_ray_number = 1;
  for (; current_ray_angle < ray_end_deg; current_ray_angle += delta_ray_deg) {
    Ray ray;
    // ray.Cast(GetPosition(), player_angle, tiles);
    ray.Cast(GetPosition(), current_ray_angle, tiles);
    rays.push_back(ray);
    ++current_ray_number;
  }
}
