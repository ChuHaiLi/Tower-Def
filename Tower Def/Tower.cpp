#include "Tower.h"
#include <cmath>

void ctower::init(const sf::Texture* texture, const cpoint& pos, const sf::Texture* bulletTex) {
    texturePtr = texture;
    position = pos;
    bulletTexture = bulletTex;

    if (texturePtr) {
        sprite.setTexture(*texturePtr);
        sprite.setOrigin(texturePtr->getSize().x / 2.f, texturePtr->getSize().y / 2.f);
        sprite.setPosition(static_cast<float>(position.getX() + 100), static_cast<float>(position.getY()));
        sprite.setScale(0.6f, 0.6f);
    }
    fireTimer = 0.f;
}

void ctower::update(float deltaTime, std::vector<cenemy>& enemies) {
    fireTimer += deltaTime;

    for (auto& b : bullets)
        b.update(deltaTime);

    // Xóa đạn
    bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
        [](const cbullet& b) { return !b.isActive(); }), bullets.end());

    if (fireTimer < fireCooldown) return;

    // Bắn quái gần nhà chính nhất
    cenemy* targetEnemy = nullptr;
    int maxPos = -1;
    float closestDist = range + 1;

    for (auto& e : enemies) {
        if (e.reachEnd()) continue;

        cpoint ePos = e.getPosition();

        float dx = static_cast<float>(ePos.getX() - position.getX());
        float dy = static_cast<float>(ePos.getY() - position.getY());
        float dist = std::sqrt(dx * dx + dy * dy);

        if (dist <= range) {
            if (e.getCurPos() > maxPos) {
                maxPos = e.getCurPos();
                closestDist = dist;
                targetEnemy = &e;
            }
        }
    }

    if (targetEnemy) {
        cbullet newBullet;
        newBullet.init(bulletTexture, position, targetEnemy->getPosition());
        bullets.push_back(newBullet);
        fireTimer = 0.f;
    }
}

void ctower::draw(sf::RenderWindow& window) {
    if (texturePtr) window.draw(sprite);
    for (auto& b : bullets) b.draw(window);
}

const std::vector<cbullet>& ctower::getBullets() const {
    return bullets;
}
