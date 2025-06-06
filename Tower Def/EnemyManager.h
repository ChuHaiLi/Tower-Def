#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <vector>
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "cenemy.h"
#include "cpoint.h"

struct EnemyInfo {
    std::string textureKey;
    float speed;
    int frameCount;
};

class EnemyManager {
private:
    struct SpawnData {
        float spawnTime;
        std::string enemyType;
    };

    std::vector<SpawnData> spawnList;
    size_t currentSpawnIndex = 0;
    float totalTime = 0.f;

    std::vector<cenemy> enemies;
    std::vector<cpoint> enemyPath;

    std::unordered_map<std::string, EnemyInfo> enemyInfoMap;

    const class TextureManager* textureManager = nullptr;

public:
    EnemyManager() = default;

    void setTextureManager(const TextureManager* texMan);
    void loadEnemyInfoDirectly();
    bool loadSpawnData(const std::string& filename);
    void setPath(const std::vector<cpoint>& path);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    int getAliveCount() const;
    //Nhận các loại quái
    std::vector<cenemy>& getEnemiesRef();
};

#endif
