#include "TowerSlot.h"

void TowerSlot::init(const sf::Texture* texture, const cpoint& pos) {
    position = pos;
    sprite.setTexture(*texture);
    sprite.setPosition(static_cast<float>(position.getX()), static_cast<float>(position.getY()));
    //Chỉnh phóng to thu nhỏ tại đây
    sprite.setScale(1.8f, 1.8f);
    sprite.setColor(sf::Color(255, 255, 255, 150));
}

void TowerSlot::setHasTower(bool value) {
    hasTower = value;
}

bool TowerSlot::towerPlaced() const {
    return hasTower;
}

const cpoint& TowerSlot::getPosition() const {
    return position;
}

bool TowerSlot::containsMouse(sf::Vector2f mousePos) const {
    return sprite.getGlobalBounds().contains(mousePos);
}

void TowerSlot::updateHighlight(sf::Vector2f mousePos) {
    if (!hasTower && containsMouse(mousePos)) {
        sprite.setColor(sf::Color(255, 255, 255, 255));
    }
    else {
        sprite.setColor(sf::Color(255, 255, 255, 150));
    }
}

void TowerSlot::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
