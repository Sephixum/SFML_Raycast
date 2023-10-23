#include "Gui.hpp"
#include "Globals.hpp"

auto Gui::Init(sf::RenderWindow &window) const noexcept -> void {
  ImGui::SFML::Init(window);
  ImGui::GetIO().IniFilename = nullptr;
}

auto Gui::Update(sf::RenderWindow &window, sf::Time time_elapsed,
                 Textures &textures) noexcept -> void {
  ImGui::SFML::Update(window, time_elapsed);
  ImGui::SetNextWindowSize(sf::Vector2f(180, 200));
  ImGui::SetNextWindowPos(sf::Vector2f(kWindow_width - 180, 0));

  static float dummy_float{0};

  ImGui::Begin("Options", nullptr,
               ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

  if (ImGui::CollapsingHeader("Textures")) {
    DrawTextures(textures);
  }

  if (ImGui::CollapsingHeader("Ray count")) {
    ImGui::SliderFloat("Rays", &dummy_float, 0.f, 100.f);
  }

  if (ImGui::CollapsingHeader("Dummy")) {
  }

  ImGui::End();
}

auto Gui::ProcessEvent(sf::Event event) const noexcept -> void {
  ImGui::SFML::ProcessEvent(event);
}

auto Gui::Render(sf::RenderWindow &window) const noexcept -> void {
  ImGui::SFML::Render(window);
}

auto Gui::ShutDown() const noexcept -> void { ImGui::SFML::Shutdown(); }

auto Gui::DrawTextures(Textures &textures) -> void {
  int textureIndex = 0;
  for (int row = 0; row < 2; ++row) {
    ImGui::Columns(4, nullptr, false);

    for (int col = 0; col < 4; ++col) {
      auto &texture = textures.textures_vector[textureIndex];
      if (ImGui::ImageButton(texture, sf::Vector2f(25, 25), 1)) {
        textures.selected_texture = &texture;
      }
      ImGui::Text("%d", textureIndex + 1);
      textureIndex++;
      ImGui::NextColumn();
    }

    ImGui::Columns(1);
  }
}
