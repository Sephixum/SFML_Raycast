#include "Gui.hpp"

auto Gui::Init(sf::RenderWindow &window) const noexcept -> void {
  ImGui::SFML::Init(window);
}

auto Gui::Update(sf::RenderWindow &window, sf::Time time_elapsed) const noexcept
    -> void {
  ImGui::SFML::Update(window, time_elapsed);

  ImGui::Begin("Hello, world !");
  ImGui::Button("Look at this button !");
  ImGui::End();
}

auto Gui::ProcessEvent(sf::Event event) const noexcept -> void {
  ImGui::SFML::ProcessEvent(event);
}

auto Gui::Render(sf::RenderWindow &window) const noexcept -> void {
  ImGui::SFML::Render(window);
}

auto Gui::ShutDown() const noexcept -> void { ImGui::SFML::Shutdown(); }
