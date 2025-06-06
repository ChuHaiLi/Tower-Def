#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include "cpoint.h"

class cbullet {
private:
    sf::Sprite sprite;
    const sf::Texture* texturePtr = nullptr;

    float speed = 1500.f;
    cpoint position;
    cpoint targetPos;

    bool active = true;

public:
    cbullet() = default;
    void init(const sf::Texture* texture, const cpoint& start, const cpoint& target, float speed = 1500.f);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    bool isActive() const;
    cpoint getPosition() const;
};

#endif
