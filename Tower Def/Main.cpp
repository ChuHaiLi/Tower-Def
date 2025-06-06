#include "GameWindow.h"
#include "Play.h"
#include "cenemy.h"
#include "EnemyManager.h"
#include<iostream>

int main() {
    const unsigned int screenWidth = 1800;
    const unsigned int screenHeight = 980;

    GameWindow gameWindow(screenWidth, screenHeight, "Tower Defense");
    sf::RenderWindow& window = gameWindow.getWindow();

    Play playState(screenWidth, screenHeight);
    playState.init(&window);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            playState.handleEvent(event);
        }

        float deltaTime = clock.restart().asSeconds();

        playState.update(deltaTime);
        playState.draw(window);
    }

    return 0;
}
