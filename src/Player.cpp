#include <MyFuncs.hpp>
#include <Player.hpp>
#include <filesystem>

Player::Player() { initPlayer(); }

Player::~Player() { delete _selectedTexture; }

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
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

  for (const auto &entry : std::filesystem::directory_iterator("textures")) {
    sf::Texture tmpTexture;
    if (!tmpTexture.loadFromFile(entry.path())) {
      throw "Failed loading textures";
    }
    _textures.push_back(tmpTexture);
  }
}

void Player::Update(float &dt) {
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
                      CELL tileMap[MAP_SIZE_WIDHT][MAP_SIZE_HEIGHT]) {
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
                     CELL tileMap[MAP_SIZE_WIDHT][MAP_SIZE_HEIGHT],
                     float currentAngle, unsigned short currentRayNumber) {
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
         CELL_TYPES::Empty == tileMap[mapPOS.x][mapPOS.y].type) {
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
    auto remainingRad = PI / 2 - (fn::degToRad(_angle) - radCurAngle);
    this->RenderWorld(window, remainingRad, sideDistX, currentRayNumber,
                      ray[1].position.y, tileMap[mapPOS.x][mapPOS.y].type);
  } break;
  case 1: {
    sideDistY -= deltaDistY * GRID_SIZE;
    ray[0].position = _spritePOS;
    ray[0].color = sf::Color::Blue;
    ray[1].position = ray[0].position + rayDir * sideDistY;
    ray[1].color = sf::Color::Blue;
    auto remainingRad = PI / 2 - (fn::degToRad(_angle) - radCurAngle);
    this->RenderWorld(window, remainingRad, sideDistY, currentRayNumber,
                      ray[1].position.x, tileMap[mapPOS.x][mapPOS.y].type);
  } break;
  }
  window.draw(ray);
}

void Player::RenderWorld(sf::RenderWindow &window, float remainingRad,
                         float hypotenuse, int currentRayNumber,
                         float rayHitOffsetFromGrid,
                         CELL_TYPES rayPositionCellType) {
  setTextureBasedOnCellType(rayPositionCellType);

  float perpendicularToWallDist = std::sin(remainingRad) * hypotenuse;
  float lineHeight = WINDOW_HEIGHT / perpendicularToWallDist;

  float textrueOffSet = std::fmod(rayHitOffsetFromGrid, GRID_SIZE) / GRID_SIZE;

  sf::VertexArray mainStripe(sf::Lines, 2);
  setUpWallStripe(mainStripe, currentRayNumber, lineHeight, textrueOffSet);

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
  window.draw(mainStripe, _selectedTexture);
  _selectedTexture = nullptr;
}

void Player::setTextureBasedOnCellType(CELL_TYPES rayPositionCellType) {
  switch (rayPositionCellType) {
  case BlueStone:
    _selectedTexture = &_textures[0];
    break;
  case ColorStone:
    _selectedTexture = &_textures[1];
    break;
  case Eagle:
    _selectedTexture = &_textures[2];
    break;
  case GreyStone:
    _selectedTexture = &_textures[3];
    break;
  case Mossy:
    _selectedTexture = &_textures[4];
    break;
  case PurpleBrick:
    _selectedTexture = &_textures[5];
    break;
  case RedBrick:
    _selectedTexture = &_textures[6];
    break;
  case Wood:
    _selectedTexture = &_textures[7];
    break;
  default:
    break;
  }
}

void Player::setUpWallStripe(sf::VertexArray &mainStripe,
                             const int currentRayNumber, const float lineHeight,
                             const float textrueOffSet) {
  mainStripe[0].position.x =
      WINDOW_WIDTH / 2.f +
      (currentRayNumber * WINDOW_WIDTH / 2.f / _visionDensity);
  mainStripe[0].position.y =
      WINDOW_HEIGHT / 2.f - lineHeight * PERPENDICULAR_LINE_SCALE;
  mainStripe[0].texCoords =
      sf::Vector2f(_selectedTexture->getSize().x * textrueOffSet, 0.f);
  mainStripe[1].position.x = mainStripe[0].position.x;
  mainStripe[1].position.y =
      WINDOW_HEIGHT / 2.f + lineHeight * PERPENDICULAR_LINE_SCALE;
  mainStripe[1].texCoords =
      sf::Vector2f(_selectedTexture->getSize().x * textrueOffSet,
                   _selectedTexture->getSize().y);
}
