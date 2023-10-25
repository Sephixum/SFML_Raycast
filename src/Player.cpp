#include "Player.hpp"
#include <SFML/System/Vector2.hpp>

Player::Player(sf::Vector2f &initial_position) {
  sprite.setPosition(initial_position);
}

Player::Player(float initial_position_x, float initial_postion_y) {
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
