#ifndef TOWERMANAGER_H
#define TOWERMANAGER_H

#include <vector>
#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>
#include "Tower.h"
#include "TextureManager.h"
#include "cpoint.h"
#include "cenemy.h"
#include "TowerSlot.h"

struct TowerInfo {
    std::string textureKey;
    std::string bulletTextureKey;
    float range;
    float fireRate;
};

class TowerManager {
private:
    std::vector<ctower> towers;
    std::unordered_map<std::string, TowerInfo> towerInfoMap;
    TextureManager* textureManager = nullptr;
    std::vector<TowerSlot> slots;
    const sf::Texture* slotTexture = nullptr;

public:
    //Xử lý tháp
    void setTextureManager(TextureManager* texMgr);
    void loadTowerInfoDirectly();
    void createTowersFromPositions(const std::vector<std::pair<std::string, cpoint>>& data);
    void update(float deltaTime, std::vector<cenemy>& enemies);
    void draw(sf::RenderWindow& window);
    // Xử lý ô đặt tháp
    void loadSlotsFromMap(const std::vector<cpoint>& slotPositions, TextureManager* texMgr, const std::string& slotTextureKey);
    void updateSlotHighlights(sf::Vector2f mousePos);
    void drawSlots(sf::RenderWindow& window);
    std::vector<TowerSlot>& getSlots();
    std::vector<ctower>& getTowers() {
        return towers;
    }
};

#endif
