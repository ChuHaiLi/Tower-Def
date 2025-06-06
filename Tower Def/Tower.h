#ifndef TOWER_H
#define TOWER_H

#include <SFML/Graphics.hpp>
#include "cpoint.h"
#include <vector>
#include "Bullet.h"
#include "cenemy.h"

class ctower {
private:
    sf::Sprite sprite;
    const sf::Texture* texturePtr = nullptr;

    cpoint position;

    float range = 250.f;
    float fireCooldown = 1.f;  // Số viên đạn / 1 giây
    float fireTimer = 0.f;

    std::vector<cbullet> bullets;

    const sf::Texture* bulletTexture = nullptr;

public:
    ctower() = default;

    void init(const sf::Texture* texture, const cpoint& pos, const sf::Texture* bulletTex);
    void update(float deltaTime, std::vector<cenemy>& enemies);
    void draw(sf::RenderWindow& window);

    const std::vector<cbullet>& getBullets() const;
};

#endif
