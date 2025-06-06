#include "Background.h"

bool Background::loadFromFile(const std::string& filename) {
    if (!texture.loadFromFile(filename))
        return false;
    sprite.setTexture(texture);
    return true;
}

void Background::setSize(unsigned int width, unsigned int height) {
    sprite.setScale(
        float(width) / texture.getSize().x,
        float(height) / texture.getSize().y
    );
}

void Background::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}