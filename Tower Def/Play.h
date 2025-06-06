#ifndef PLAY_H
#define PLAY_H

#include "MapGame.h"
#include "EnemyManager.h"
#include <SFML/Graphics.hpp>
#include "TowerManager.h"
#include "TextureManager.h"

class Play {
private:
    MapGame map;
    EnemyManager enemyManager;
    sf::Font font;
    sf::Text debugText;
    TowerManager towerManager;
    TextureManager textureManager;
    sf::RenderWindow* windowPtr = nullptr;
public:
    Play(unsigned int screenWidth, unsigned int screenHeight);
    void init(sf::RenderWindow* win);
    void handleEvent(sf::Event& event);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
};

#endif
