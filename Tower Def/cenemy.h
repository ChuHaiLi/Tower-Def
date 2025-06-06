#ifndef CENEMY_H
#define CENEMY_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "cpoint.h"

class cenemy {
private:
    int curPos = 0;
    std::vector<cpoint> path;
    float speed = 0.f;

    const sf::Texture* texturePtr = nullptr;
    sf::Sprite sprite;

    int frameWidth = 0;
    int frameHeight = 0;
    int currentFrame = 0;
    int frameCount = 1;
    float frameDuration = 0.1f;
    float frameTimer = 0.f;

public:
    cenemy() = default;
    void init(float speed, const std::vector<cpoint>& gamePath, const sf::Texture* texture, int frameCount = 1);
    void setSpeed(float sp);
    float getSpeed() const;
    void setPath(const std::vector<cpoint>& gamePath);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    bool reachEnd() const;
    cpoint getPosition() const;
    int getCurPos() const;
};

#endif
