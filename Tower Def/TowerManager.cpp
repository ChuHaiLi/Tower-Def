#include "TowerManager.h"
#include "TowerSlot.h"
#include <iostream>

void TowerManager::setTextureManager(TextureManager* texMgr) {
    textureManager = texMgr;
}

void TowerManager::loadTowerInfoDirectly() {
    // Key_Tháp; Key_Đạn; Tốc độ đạn; Số đạn mỗi giây.
    towerInfoMap["MeoTom"] = { "Tom", "PhiTieu", 1500.f, 2.f };
    // Thêm tại đây
}

void TowerManager::createTowersFromPositions(const std::vector<std::pair<std::string, cpoint>>& data) {
    for (const auto& [type, pos] : data) {
        auto it = towerInfoMap.find(type);
        if (it != towerInfoMap.end() && textureManager) {
            const TowerInfo& info = it->second;

            const sf::Texture* towerTex = textureManager->getTexture(info.textureKey);
            const sf::Texture* bulletTex = textureManager->getTexture(info.bulletTextureKey);

            if (!towerTex || !bulletTex) {
                std::cerr << "Failed texture for tower or bullet: " << type << "\n";
                continue;
            }

            ctower tower;
            tower.init(towerTex, pos, bulletTex);
            towers.push_back(tower);
        }
    }
}

void TowerManager::update(float deltaTime, std::vector<cenemy>& enemies) {
    for (auto& tower : towers) {
        tower.update(deltaTime, enemies);
    }
}

void TowerManager::draw(sf::RenderWindow& window) {
    for (auto& tower : towers) {
        tower.draw(window);
    }
}

void TowerManager::loadSlotsFromMap(const std::vector<cpoint>& slotPositions, TextureManager* texMgr, const std::string& slotTextureKey) {
    slotTexture = texMgr->getTexture(slotTextureKey);
    if (!slotTexture) return;

    for (const auto& pos : slotPositions) {
        TowerSlot slot;
        slot.init(slotTexture, pos);
        slots.push_back(slot);
    }
}

void TowerManager::updateSlotHighlights(sf::Vector2f mousePos) {
    for (auto& slot : slots) {
        slot.updateHighlight(mousePos);
    }
}

void TowerManager::drawSlots(sf::RenderWindow& window) {
    for (auto& slot : slots) {
        slot.draw(window);
    }
}

std::vector<TowerSlot>& TowerManager::getSlots() {
    return slots;
}