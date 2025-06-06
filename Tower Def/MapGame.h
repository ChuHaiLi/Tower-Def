#ifndef MAPGAME_H
#define MAPGAME_H

#include <vector>
#include "Background.h"
#include "MapGrid.h"
#include "cpoint.h"

class MapGame {
private:
    Background background;
    MapGrid mapGrid;

    std::vector<cpoint> pathPoints;     // Đường đi cho quái
    std::vector<cpoint> towerPositions; // Vị trí đặt tháp
    cpoint homePosition;                 // Vị trí nhà chính

public:
    MapGame(unsigned int screenWidth, unsigned int screenHeight);

    bool loadBackground(const std::string& filename);
    void draw(sf::RenderWindow& window);

    void loadPath(const std::string& filename);
    void loadTowerPositions(const std::string& filename);
    void loadHomePosition(const std::string& filename);

    const std::vector<cpoint>& getPathPoints() const;
    const std::vector<cpoint>& getTowerPositions() const;
    cpoint getHomePosition() const;

    MapGrid& getMapGrid();
};

#endif
