#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <string>

class Background {
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    bool loadFromFile(const std::string& filename);
    void draw(sf::RenderWindow& window);

    void setSize(unsigned int width, unsigned int height);
};

#endif
