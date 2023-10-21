#include "Engine.hpp"

Engine::Engine() {
  InitWindow();
  InitVariables();
}

Engine::~Engine() { gui_.ShutDown(); }

auto Engine::InitWindow() noexcept -> void {
  window_ = std::make_unique<sf::RenderWindow>(
      sf::VideoMode(kWindow_width, kWindow_height), "My sfml program");
  window_->setFramerateLimit(60);
}

auto Engine::InitVariables() noexcept -> void { gui_.Init(*window_); }

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

auto Engine::Update() -> void { gui_.Update(*window_, delta_clock_.restart()); }

auto Engine::Render() -> void {
  window_->clear();
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
