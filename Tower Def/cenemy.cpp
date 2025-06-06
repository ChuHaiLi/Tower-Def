#include "cenemy.h"
#include <cmath>
#include <iostream>

void cenemy::init(float speed, const std::vector<cpoint>& gamePath, const sf::Texture* texture, int frameCount) {
    this->speed = speed;
    this->texturePtr = texture;
    this->frameCount = frameCount;

    if (!texturePtr) {
        std::cerr << "Null texture pointer!\n";
        return;
    }

    frameWidth = texturePtr->getSize().x / frameCount;
    frameHeight = texturePtr->getSize().y;

    sprite.setTexture(*texturePtr);
    sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
    sprite.setOrigin(frameWidth / 2.f, frameHeight / 2.f);
    sprite.setScale(0.4f, 0.5f);

    setPath(gamePath);
}

void cenemy::setSpeed(float sp) {
    if (sp > 0) this->speed = sp;
}

float cenemy::getSpeed() const {
    return this->speed;
}

void cenemy::setPath(const std::vector<cpoint>& gamePath) {
    this->path = gamePath;
    curPos = 0;

    if (!path.empty()) {
        sprite.setPosition(static_cast<float>(path[0].getX()), static_cast<float>(path[0].getY()));
    }
}

void cenemy::update(float deltaTime) {
    if (curPos + 1 >= path.size()) return;

    sf::Vector2f current = sprite.getPosition();
    sf::Vector2f target(static_cast<float>(path[curPos + 1].getX()), static_cast<float>(path[curPos + 1].getY()));
    sf::Vector2f dir = target - current;
    float dist = std::sqrt(dir.x * dir.x + dir.y * dir.y);

    if (dist < 1.f) {
        curPos++;
    }
    else {
        sprite.move((speed * deltaTime / dist) * dir);
    }

    frameTimer += deltaTime;
    if (frameTimer >= frameDuration) {
        frameTimer = 0.f;
        currentFrame = (currentFrame + 1) % frameCount;
        sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));
    }
}

void cenemy::draw(sf::RenderWindow& window) {
    if (texturePtr) window.draw(sprite);
}

bool cenemy::reachEnd() const {
    return curPos + 1 >= path.size();
}

cpoint cenemy::getPosition() const {
    sf::Vector2f pos = sprite.getPosition();
    return cpoint(static_cast<int>(pos.x), static_cast<int>(pos.y), 0);
}

int cenemy::getCurPos() const{
    return curPos;
}