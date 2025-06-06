#include "EnemyManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "TextureManager.h"

void EnemyManager::setTextureManager(const TextureManager* texMan) {
    textureManager = texMan;
}

void EnemyManager::loadEnemyInfoDirectly() {
    // key texture trong TextureManager
    enemyInfoMap["camap"] = { "ca_map", 120.f, 12 };
    // Thêm quái ở đây(làm y như ở trên):

}

bool EnemyManager::loadSpawnData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    spawnList.clear();
    float time;
    std::string type;

    while (file >> time >> type) {
        spawnList.push_back({ time, type });
    }

    return true;
}

void EnemyManager::setPath(const std::vector<cpoint>& path) {
    this->enemyPath = path;
}

void EnemyManager::update(float deltaTime) {
    totalTime += deltaTime;

    while (currentSpawnIndex < spawnList.size() && totalTime >= spawnList[currentSpawnIndex].spawnTime) {
        const auto& spawn = spawnList[currentSpawnIndex];

        auto it = enemyInfoMap.find(spawn.enemyType);
        if (it != enemyInfoMap.end() && textureManager) {
            const EnemyInfo& info = it->second;

            const sf::Texture* tex = textureManager->getTexture(info.textureKey);
            if (!tex) {
                std::cerr << "Texture not found in TextureManager: " << info.textureKey << std::endl;
            }
            else {
                cenemy e;
                e.init(info.speed, enemyPath, tex, info.frameCount);
                enemies.push_back(e);
            }
        }
        else {
            std::cerr << "Enemy type not found or textureManager nullptr: " << spawn.enemyType << std::endl;
        }

        currentSpawnIndex++;
    }

    for (auto& e : enemies) {
        e.update(deltaTime);
    }

    enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
        [](const cenemy& e) { return e.reachEnd(); }), enemies.end());
}

void EnemyManager::draw(sf::RenderWindow& window) {
    for (auto& e : enemies) {
        e.draw(window);
    }
}

int EnemyManager::getAliveCount() const {
    return (int)enemies.size();
}

std::vector<cenemy>& EnemyManager::getEnemiesRef() {
    return enemies;
}
