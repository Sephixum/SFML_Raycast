#include <Player.hpp>
#include <MyFuncs.hpp>

Player::Player() { initPlayer(); }

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();
  target.draw(sprite, states);
}

void Player::initPlayer() {
  _angle = 45.f;

  sprite.setRotation(_angle);
  sprite.setOrigin(fn::averageOfVertexArray(sprite.vertices));
  sprite.setPosition(_spritePOS);

  _spritePOS.x = WINDOW_WIDTH / 4.f;
  _spritePOS.y = WINDOW_HEIGHT / 4.f;

  _visionDensity = 900;

  if (!_texture.loadFromFile("textures/eagle.png")) {
    throw "Texture does not exist or cannot be loaded.\n";
  }
}

void Player::Update(float dt) {
  auto playerAngleRads = fn::degToRad(_angle);

  sf::Vector2f horizontalDiff(SPEED * dt * std::cos(playerAngleRads),
                              SPEED * dt * std::sin(playerAngleRads));

  sf::Vector2f verticallDiff(SPEED * dt * std::cos(playerAngleRads + PI / 2),
                             SPEED * dt * std::sin(playerAngleRads + PI / 2));

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    _spritePOS += horizontalDiff;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    _spritePOS -= horizontalDiff;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    _spritePOS -= verticallDiff;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    _spritePOS += verticallDiff;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
    _angle -= SPEED * dt;
    if (_angle < 0) {
      _angle += 360;
    }
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
    _angle += SPEED * dt;
    if (_angle > 360) {
      _angle -= 360;
    }
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
    _angle = 0;
    _visionDensity = 900;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    if (_visionDensity > 10) {
      _visionDensity -= 10;
    }
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    if (_visionDensity < 900) {
      _visionDensity += 10;
    }
  }
  sprite.setPosition(_spritePOS);
  sprite.setRotation(_angle);
}

void Player::DrawRays(sf::RenderWindow &window,
                      Cell tileMap[MAP_SIZE_WIDHT][MAP_SIZE_HEIGHT]) {
  auto halfOfFOV = FOV / 2.f;
  auto rayIncrease = FOV / _visionDensity;
  float currentAngle = _angle - halfOfFOV;
  float maximumFovDeg = _angle + halfOfFOV;
  unsigned short currentRayNumber = 1;

  for (; currentAngle < maximumFovDeg; currentAngle += rayIncrease) {
    DrawRay(window, tileMap, currentAngle, currentRayNumber);
    ++currentRayNumber;
  }
}

void Player::DrawRay(sf::RenderWindow &window,
                     Cell tileMap[MAP_SIZE_WIDHT][MAP_SIZE_HEIGHT],
                     float currentAngle, unsigned short rayNum) {
  sf::Vector2i mapPOS((_spritePOS.x / GRID_SIZE), (_spritePOS.y / GRID_SIZE));

  float radCurAngle = fn::degToRad(currentAngle);

  sf::Vector2f rayDir((std::cos(radCurAngle)), (std::sin(radCurAngle)));

  float deltaDistX =
      std::sqrt(1 + (rayDir.y * rayDir.y) / (rayDir.x * rayDir.x));
  float deltaDistY =
      std::sqrt(1 + (rayDir.x * rayDir.x) / (rayDir.y * rayDir.y));

  float sideDistX;
  float sideDistY;
  sf::Vector2i step;
  if (rayDir.x < 0) {
    step.x = -1;
    sideDistX = (_spritePOS.x - (mapPOS.x * GRID_SIZE)) * deltaDistX;
  } else {
    step.x = 1;
    sideDistX = (((mapPOS.x + 1.0f) * GRID_SIZE) - _spritePOS.x) * deltaDistX;
  }
  if (rayDir.y < 0) {
    step.y = -1;
    sideDistY = (_spritePOS.y - (mapPOS.y * GRID_SIZE)) * deltaDistY;
  } else {
    step.y = 1;
    sideDistY = (((mapPOS.y + 1.0f) * GRID_SIZE) - _spritePOS.y) * deltaDistY;
  }

  int side;
  while ((mapPOS.x * GRID_SIZE + 1) < WINDOW_WIDTH / 2.f &&
         (mapPOS.y * GRID_SIZE + 1) < WINDOW_HEIGHT &&
         (mapPOS.x * GRID_SIZE) > -1 &&
         tileMap[mapPOS.x][mapPOS.y].type != CellTypes::Wall) {
    if (sideDistX < sideDistY) {
      sideDistX += (deltaDistX * GRID_SIZE);
      mapPOS.x += step.x;
      side = 0;
    } else {
      sideDistY += (deltaDistY * GRID_SIZE);
      mapPOS.y += step.y;
      side = 1;
    }
  }

  sf::VertexArray ray(sf::Lines, 2);
  switch (side) {
  case 0: {
    sideDistX -= deltaDistX * GRID_SIZE;
    ray[0].position = _spritePOS;
    ray[0].color = sf::Color::Red;
    ray[1].position = ray[0].position + rayDir * sideDistX;
    ray[1].color = sf::Color::Red;
    this->RenderWorld(window, (PI / 2 - (fn::degToRad(_angle) - radCurAngle)),
                      sideDistX, rayNum, sf::Color(255, 255, 255, 255),
                      ray[1].position.y);
  } break;
  case 1: {
    sideDistY -= deltaDistY * GRID_SIZE;
    ray[0].position = _spritePOS;
    ray[0].color = sf::Color::Blue;
    ray[1].position = ray[0].position + rayDir * sideDistY;
    ray[1].color = sf::Color::Blue;
    this->RenderWorld(window, (PI / 2 - (fn::degToRad(_angle) - radCurAngle)),
                      sideDistY, rayNum, sf::Color(40, 40, 40, 255),
                      ray[1].position.x);
  } break;
  }
  window.draw(ray);
}

void Player::RenderWorld(sf::RenderWindow &window, float remainingRad,
                         float hypotenuse, unsigned short rayNum,
                         sf::Color color, float rayHitOffsetFromGrid) {
  float perpWallDist = std::sin(remainingRad) * hypotenuse;
  float lineHeight = WINDOW_HEIGHT / perpWallDist;

  float textrueOffSet = std::fmod(rayHitOffsetFromGrid, GRID_SIZE) / GRID_SIZE;

  sf::VertexArray mainStripe(sf::Lines, 2);
  mainStripe[0].position.x =
      WINDOW_WIDTH / 2.f + (rayNum * WINDOW_WIDTH / 2.f / _visionDensity);
  mainStripe[0].position.y = WINDOW_HEIGHT / 2.f - lineHeight * 15.f;
  mainStripe[0].texCoords =
      sf::Vector2f(_texture.getSize().x * textrueOffSet, 0.0f);
  mainStripe[1].position.x = mainStripe[0].position.x;
  mainStripe[1].position.y = WINDOW_HEIGHT / 2.f + lineHeight * 15.f;
  mainStripe[1].texCoords =
      sf::Vector2f(_texture.getSize().x * textrueOffSet, _texture.getSize().y);

  sf::VertexArray floorStripe(sf::Lines, 2);
  floorStripe[0].position.x = mainStripe[1].position.x;
  floorStripe[0].position.y = mainStripe[1].position.y;
  floorStripe[0].color = sf::Color(120, 120, 120, 255);
  floorStripe[1].position.x = mainStripe[1].position.x;
  floorStripe[1].position.y = WINDOW_HEIGHT;
  floorStripe[1].color = sf::Color(120, 120, 120, 255);

  sf::VertexArray skyStripe(sf::Lines, 2);
  skyStripe[0].position.x = mainStripe[0].position.x;
  skyStripe[0].position.y = WINDOW_HEIGHT / 2.f;
  skyStripe[1].color = sf::Color(0, 197, 255, 255);
  skyStripe[1].position.x = mainStripe[0].position.x;
  skyStripe[1].position.y = 0;
  skyStripe[0].color = sf::Color(255, 196, 0, 255);

  window.draw(skyStripe);
  window.draw(floorStripe);
  window.draw(mainStripe, &_texture);
}
