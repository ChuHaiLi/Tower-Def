#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <SFML/Graphics.hpp>

class GameWindow {
public:
    GameWindow(unsigned int width, unsigned int height, const std::string& title);
    sf::RenderWindow& getWindow();

private:
    sf::RenderWindow window;
};

#endif
