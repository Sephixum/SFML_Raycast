#include "Gui.hpp"
#include "Globals.hpp"
#include "imgui.h"

auto Gui::Init(sf::RenderWindow &window) const noexcept -> void {
  ImGui::SFML::Init(window);
  ImGui::GetIO().IniFilename = nullptr;
}

auto Gui::Update(sf::RenderWindow &window, sf::Time time_elapsed,
                 Textures &textures, int *vision_density) noexcept -> void {
  ImGui::SFML::Update(window, time_elapsed);

  static float dummy_float{0};

  ImGui::Begin("Options", nullptr,
               ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                   ImGuiWindowFlags_AlwaysAutoResize);

  ImGui::SetWindowSize(ImVec2(200, 0), ImGuiCond_Always);
  ImGui::SetWindowPos(sf::Vector2f(kMap_width, 0));

  if (ImGui::CollapsingHeader("Textures        ")) {
    DrawTextures(textures);
  }
  if (ImGui::CollapsingHeader("Ray count")) {
    ImGui::SliderInt("Rays", vision_density, 6, kWindow_width);
  }
  if (ImGui::CollapsingHeader("Dummy")) {
  }

  ImGui::End();

  ImGui::Begin("Texture", nullptr,
               ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
                   ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);
  ImGui::SetWindowPos(sf::Vector2f(0, kMap_height));
  ImGui::Image(*textures.selected_texture);
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
