#ifndef TOWERSLOT_H
#define TOWERSLOT_H
#include <SFML/Graphics.hpp>
#include "cpoint.h"

class TowerSlot {
private:
    cpoint position;
    bool hasTower = false;
    sf::Sprite sprite;

public:
    void init(const sf::Texture* texture, const cpoint& pos);
    void setHasTower(bool value);
    bool towerPlaced() const;
    const cpoint& getPosition() const;
    bool containsMouse(sf::Vector2f mousePos) const;
    void updateHighlight(sf::Vector2f mousePos);
    void draw(sf::RenderWindow& window);
};

#endif