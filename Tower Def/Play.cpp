#include "Play.h"
#include <iostream>
Play::Play(unsigned int screenWidth, unsigned int screenHeight)
    : map(screenWidth, screenHeight) {}

void Play::init(sf::RenderWindow* win) {
    windowPtr = win;

    // 1. Load background
    if (!map.loadBackground("MapGame/Map1.jpg")) {
        std::cerr << "Failed to load map\n";
        return;
    }

    // 2. Load all textures
    textureManager.loadTexture("ca_map", "Enemy/Picture/Tralala/CaMap.png");
    if (!textureManager.loadTexture("Tom", "Enemy/Picture/Tralala/Tom.png"))
        std::cerr << "Failed load tower." << std::endl;
    if (!textureManager.loadTexture("PhiTieu", "Enemy/Picture/Tralala/PhiTieu.png"))
        std::cerr << "Failed load bullet." << std::endl;
    if (!textureManager.loadTexture("Tower_Slot", "Tower/DatThap.png"))
        std::cerr << "Failed Tower slots" << std::endl;

    // 3. Load font
    if (!font.loadFromFile("Font/Heku.otf"))
        std::cerr << "Failed to load font.\n";
    debugText.setFont(font);
    debugText.setCharacterSize(16);
    debugText.setFillColor(sf::Color::White);
    debugText.setPosition(10.f, 10.f);

    // 4. Load map path and tower positions
    map.loadPath("MapGame/PathGame/path1.txt");
    map.loadTowerPositions("MapGame/PathGame/tower.txt");

    // 5. Set up managers
    enemyManager.setTextureManager(&textureManager);
    towerManager.setTextureManager(&textureManager);

    // 6. Set up enemy
    enemyManager.loadEnemyInfoDirectly();
    enemyManager.setPath(map.getPathPoints());
    if (!enemyManager.loadSpawnData("Enemy/Spawn/spawn.txt"))
        std::cerr << "Failed to load spawn data\n";

    // 7. Set up tower slots (after tower positions are loaded)
    towerManager.loadSlotsFromMap(map.getTowerPositions(), &textureManager, "Tower_Slot");

    // 8. Set up towers
    towerManager.loadTowerInfoDirectly();
    //std::vector<std::pair<std::string, cpoint>> towerData;
    //for (const auto& pos : map.getTowerPositions()) {
      //  towerData.emplace_back("MeoTom", pos);
    //}
    //towerManager.createTowersFromPositions(towerData);
}

void Play::handleEvent(sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mouseWorldPos = windowPtr->mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
        for (auto& slot : towerManager.getSlots()) {
            if (!slot.towerPlaced() && slot.containsMouse(mouseWorldPos)) {
                // Sau khi chọn tháp, đặt tháp vào slot (ví dụ đặt sẵn MeoTom)
                //Chỉnh menu tháp tại đây!
                ctower newTower;
                newTower.init(
                    textureManager.getTexture("Tom"),
                    slot.getPosition(),
                    textureManager.getTexture("PhiTieu")
                );
                towerManager.getTowers().push_back(newTower);
                slot.setHasTower(true);
                break;
            }
        }
    }
}

void Play::update(float deltaTime) {
    enemyManager.update(deltaTime);
    towerManager.update(deltaTime, enemyManager.getEnemiesRef());

    // Vị trí chuột
    sf::Vector2i mousePixelPos = sf::Mouse::getPosition(*windowPtr);
    sf::Vector2f mouseWorldPos = windowPtr->mapPixelToCoords(mousePixelPos);
    towerManager.updateSlotHighlights(mouseWorldPos);
}
void Play::draw(sf::RenderWindow& window) {
    window.clear();
    map.draw(window);
    towerManager.drawSlots(window);
    towerManager.draw(window);
    enemyManager.draw(window);
    debugText.setString("Enemies alive: " + std::to_string(enemyManager.getAliveCount()));
    window.draw(debugText);
    window.display();
}
