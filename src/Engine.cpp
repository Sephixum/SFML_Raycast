#include "Engine.hpp"

Engine::Engine() {
  InitWindow();
  InitVariables();
}

Engine::~Engine() { gui_.ShutDown(); }

auto Engine::InitWindow() noexcept -> void {
  window_ = std::make_unique<sf::RenderWindow>(
      sf::VideoMode(kWindow_width, kWindow_height), "Develop window");
  window_->setFramerateLimit(60);
}

auto Engine::InitVariables() noexcept -> void {
  textures_.Init();
  gui_.Init(*window_);
  sprite.setTexture(*(textures_.selected_texture + 1));
}

auto Engine::PollEvents() -> void {
  while (window_->pollEvent(event_)) {
    gui_.ProcessEvent(event_);
    switch (event_.type) {
    case sf::Event::Closed: {
      window_->close();
    } break;
    case sf::Event::KeyPressed: {
      if (event_.key.code == sf::Keyboard::Escape) {
        window_->close();
      }
    } break;
    }
  }
}

auto Engine::Update() noexcept -> void {
  gui_.Update(*window_, delta_clock_.restart(), textures_);
  sprite.setTexture(*textures_.selected_texture);
}

auto Engine::Render() noexcept -> void {
  window_->clear();
  mini_map_.Draw(sprite);
  window_->draw(sprite);
  gui_.Render(*window_);
  window_->display();
}

auto Engine::Run() noexcept -> void {
  while (window_->isOpen()) {
    PollEvents();
    Update();
    Render();
  }
}
