#include "GameWindow.h"

GameWindow::GameWindow(unsigned int width, unsigned int height, const std::string& title)
    : window(sf::VideoMode(width, height), title) {
    window.setFramerateLimit(60);
}

sf::RenderWindow& GameWindow::getWindow() {
    return window;
}
