#include "Bullet.h"
#include <cmath>

void cbullet::init(const sf::Texture* texture, const cpoint& start, const cpoint& target, float speed) {
    texturePtr = texture;
    this->speed = speed;
    position = start;
    targetPos = target;

    if (texturePtr) {
        sprite.setTexture(*texturePtr);
        sprite.setOrigin(texturePtr->getSize().x / 2.f, texturePtr->getSize().y / 2.f);
        sprite.setPosition(static_cast<float>(position.getX()), static_cast<float>(position.getY()));
        sprite.setScale(0.3f, 0.3f);
    }
    active = true;
}

void cbullet::update(float deltaTime) {
    if (!active) return;

    sf::Vector2f posF(static_cast<float>(position.getX()), static_cast<float>(position.getY()));
    sf::Vector2f targetF(static_cast<float>(targetPos.getX()), static_cast<float>(targetPos.getY()));

    sf::Vector2f dir = targetF - posF;
    float dist = std::sqrt(dir.x * dir.x + dir.y * dir.y);

    if (dist < speed * deltaTime) {
        position = targetPos;
        active = false;
    }
    else {
        sf::Vector2f movement = (speed * deltaTime / dist) * dir;
        posF += movement;
        position = cpoint(static_cast<int>(posF.x), static_cast<int>(posF.y), 0);
        sprite.setPosition(posF);
    }
}

void cbullet::draw(sf::RenderWindow& window) {
    if (active && texturePtr)
        window.draw(sprite);
}

bool cbullet::isActive() const {
    return active;
}

cpoint cbullet::getPosition() const {
    return position;
}
