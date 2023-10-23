#include "Textures.hpp"

// Textures::Textures() {
// }

auto Textures::Init() -> void {
  textures_vector.reserve(8);

  std::cout << "\n===========Loading Textures===========\n";
  for (const auto &entry : std::filesystem::directory_iterator("textures")) {
    sf::Texture temp_texture;
    auto entry_path = entry.path().string();
    if (!temp_texture.loadFromFile(entry_path)) {
      std::cout << "Failed to load texture " << entry_path << ".\n";
    }
    std::cout << "Texture " << entry_path << " loaded.\n";
    textures_vector.push_back(std::move(temp_texture));
  }

  selected_texture = &textures_vector[0];
  std::cout << "========Loading Textures Done=========\n";
}
