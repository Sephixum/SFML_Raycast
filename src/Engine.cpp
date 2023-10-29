#include "Engine.hpp"
#include "Ray.hpp"

Engine::Engine() {
  InitWindow();
  InitVariables();
}

Engine::~Engine() { gui_.ShutDown(); }

auto Engine::InitWindow() noexcept -> void {
  window_ = std::make_unique<sf::RenderWindow>(
      sf::VideoMode(kWindow_width, kWindow_height), "Develop window",
      sf::Style::Resize);
  window_->setFramerateLimit(60);
  window_->setKeyRepeatEnabled(true);
}

auto Engine::InitVariables() noexcept -> void {
  textures_.Init();
  gui_.Init(*window_);
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
    case sf::Event::Resized: {
      window_->setSize(sf::Vector2u(kWindow_width, kWindow_height));
      window_->setView(
          sf::View(sf::FloatRect(0, 0, event_.size.width, event_.size.height)));

    } break;
    }
  }
}

auto Engine::Update() noexcept -> void {
  mini_map_.Update();
  gui_.Update(*window_, delta_clock_.restart(), textures_,
              &mini_map_.sprite_.vision_density);
  mini_map_.SpriteUpdate(delta_clock_.restart().asSeconds());
}

auto Engine::Render() const noexcept -> void {
  window_->clear();
  window_->draw(sf::Sprite(mini_map_.GetTexture()));
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
