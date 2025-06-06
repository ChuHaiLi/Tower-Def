#include "MapGame.h"
#include <fstream>
#include <iostream>

MapGame::MapGame(unsigned int screenWidth, unsigned int screenHeight)
    : mapGrid(cpoint::map_row, cpoint::map_col) {
    mapGrid.initializeGrid(screenWidth, screenHeight);
}

bool MapGame::loadBackground(const std::string& filename) {
    if (!background.loadFromFile(filename)) {
        std::cerr << "Failed to load background: " << filename << std::endl;
        return false;
    }
    background.setSize(mapGrid.getCellWidth() * cpoint::map_col,
        mapGrid.getCellHeight() * cpoint::map_row);
    return true;
}

void MapGame::draw(sf::RenderWindow& window) {
    background.draw(window);
}

void MapGame::loadPath(const std::string& filename) {
    pathPoints.clear();
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cerr << "Failed to open path file: " << filename << std::endl;
        return;
    }
    int r, c;
    while (in >> r >> c) {
        cpoint gridPoint(r, c, 0);
        pathPoints.push_back(gridPoint);
    }
}

void MapGame::loadTowerPositions(const std::string& filename) {
    towerPositions.clear();
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cerr << "Failed to open tower positions file: " << filename << std::endl;
        return;
    }
    int r, c;
    while (in >> r >> c) {
        cpoint gridPoint(r, c, 0);
        towerPositions.push_back(gridPoint);
    }
}

void MapGame::loadHomePosition(const std::string& filename) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cerr << "Failed to open home position file: " << filename << std::endl;
        return;
    }
    int r, c;
    if (in >> r >> c) {
        cpoint gridPoint(r, c, 0);
        homePosition = mapGrid.RCtoXY(gridPoint);
    }
}

const std::vector<cpoint>& MapGame::getPathPoints() const {
    return pathPoints;
}

const std::vector<cpoint>& MapGame::getTowerPositions() const {
    return towerPositions;
}

cpoint MapGame::getHomePosition() const {
    return homePosition;
}

MapGrid& MapGame::getMapGrid() {
    return mapGrid;
}
