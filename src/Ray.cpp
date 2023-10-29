#include "Ray.hpp"
#include "Globals.hpp"
#include "Utils.hpp"
#include <vector>

auto Ray::draw(sf::RenderTarget &target, sf::RenderStates states) const
    -> void {
  target.draw(stripe_, states);
}

Ray::Ray() : stripe_(sf::PrimitiveType::LineStrip, 2) {
  stripe_[0].position =
      sf::Vector2f(kWindow_width / 2.f - 100, kWindow_height / 2.f - 100);
  stripe_[1].position =
      sf::Vector2f(kWindow_width / 2.f + 100, kWindow_height / 2.f + 100);
}

Ray::Ray(const sf::Vector2f begin, const sf::Vector2f end)
    : stripe_(sf::PrimitiveType::LineStrip, 2) {
  stripe_[0].position =
      sf::Vector2f(kWindow_width / 2.f - 100, kWindow_height / 2.f - 100);
  stripe_[1].position =
      sf::Vector2f(kWindow_width / 2.f + 100, kWindow_height / 2.f + 100);
}

auto Ray::SetPosition(const sf::Vector2f begin, const sf::Vector2f end)
    -> void {
  stripe_[0].position = begin;
  stripe_[1].position = end;
}

auto Ray::SetColor(const sf::Color begin_color, const sf::Color end_color)
    -> void {
  stripe_[0].color = begin_color;
  stripe_[1].color = end_color;
}

auto Ray::SetTexCoord(const sf::Vector2f begin_coords,
                      const sf::Vector2f end_coords) -> void {
  stripe_[0].texCoords = begin_coords;
  stripe_[1].texCoords = end_coords;
}

auto Ray::Cast(const sf::Vector2f begin_position, float angle_of_ray,
               const std::vector<TilePtrVec> &tiles) -> Ray {
  auto begin_tile = sf::Vector2i(begin_position.x / kTile_width,
                                 begin_position.y / kTile_width);
  auto ray_angle_in_rads = Utils::DegreeToRads(angle_of_ray);
  auto ray_direction =
      sf::Vector2f(std::cos(ray_angle_in_rads), std::sin(ray_angle_in_rads));

  float delta_distance_of_x =
      std::sqrt(1 + (ray_direction.y * ray_direction.y) /
                        (ray_direction.x * ray_direction.x));
  float delta_distance_of_y =
      std::sqrt(1 + (ray_direction.x * ray_direction.x) /
                        (ray_direction.y * ray_direction.y));

  float side_distance_x{0.f};
  float side_distance_y{0.f};
  sf::Vector2i step;

  if (ray_direction.x < 0) {
    step.x = -1;
    side_distance_x =
        (begin_position.x - (begin_tile.x * kTile_width)) * delta_distance_of_x;
  } else {
    step.x = 1;
    side_distance_x =
        (((begin_tile.x + 1.0f) * kTile_width) - begin_position.x) *
        delta_distance_of_x;
  }
  if (ray_direction.y < 0) {
    step.y = -1;
    side_distance_y =
        (begin_position.y - (begin_tile.y * kTile_width)) * delta_distance_of_y;
  } else {
    step.y = 1;
    side_distance_y =
        (((begin_tile.y + 1.0f) * kTile_width) - begin_position.y) *
        delta_distance_of_y;
  }

  int side{-1};
  /*
   * Actuall DDA
   */
  while (tiles[begin_tile.x][begin_tile.y]->type == TileType::empty) {
    if (side_distance_x < side_distance_y) {
      side_distance_x += (delta_distance_of_x * kTile_width);
      begin_tile.x += step.x;
      side = 0;
    } else {
      side_distance_y += (delta_distance_of_y * kTile_width);
      begin_tile.y += step.y;
      side = 1;
    }
  }

  switch (side) {
  case 0: {
    side_distance_x -= delta_distance_of_x * kTile_width;
    stripe_[0].position = begin_position;
    stripe_[0].color = sf::Color::Red;
    stripe_[1].position = begin_position + ray_direction * side_distance_x;
    stripe_[1].color = sf::Color::Red;
  } break;
  case 1: {
    side_distance_y -= delta_distance_of_y * kTile_width;
    stripe_[0].position = begin_position;
    stripe_[0].color = sf::Color::Blue;
    stripe_[1].position = begin_position + ray_direction * side_distance_y;
    stripe_[1].color = sf::Color::Blue;
  } break;
  }

  return *this;
}
