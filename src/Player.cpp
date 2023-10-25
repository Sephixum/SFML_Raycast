#include "Player.hpp"
#include "Globals.hpp"
#include "imgui.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

Player::Player(sf::Vector2f &initial_position) : player_angle(45.f) {
  sprite.setPosition(initial_position);
}

Player::Player(float initial_position_x, float initial_postion_y)
    : player_angle(45.f) {
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

  ImGui::Text("(%f, %f)", new_sprite_position.x, new_sprite_position.y);

  sprite.setPosition(new_sprite_position);
  sprite.setRotation(player_angle);

  // if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
  //   new_sprite_position += horizontal_difference;
  // }
  //
  // if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
  //   new_sprite_position += horizontal_difference;
  // }
}
