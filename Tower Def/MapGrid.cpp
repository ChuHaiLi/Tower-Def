#include "MapGrid.h"

float MapGrid::cellWidth = 0.f;
float MapGrid::cellHeight = 0.f;

MapGrid::MapGrid(unsigned int rows, unsigned int cols) : rows(rows), cols(cols) {
    grid.resize(rows, std::vector<cpoint>(cols));
}

void MapGrid::initializeGrid(int screenWidth, int screenHeight) {
    cellWidth = float(screenWidth) / cols;
    cellHeight = float(screenHeight) / rows;

    for (unsigned int row = 0; row < rows; ++row) {
        for (unsigned int col = 0; col < cols; ++col) {
            int x = static_cast<int>(col * cellWidth);
            int y = static_cast<int>(row * cellHeight);
            grid[row][col] = cpoint(x, y, 0);
        }
    }
}

cpoint MapGrid::XYtoRC(cpoint pixel) {
    int row = static_cast<int>(pixel.getY() / cellHeight);
    int col = static_cast<int>(pixel.getX() / cellWidth);
    return cpoint(row, col, pixel.getC());
}

cpoint MapGrid::RCtoXY(cpoint gridPoint) {
    int x = static_cast<int>(gridPoint.getY() * cellWidth);
    int y = static_cast<int>(gridPoint.getX() * cellHeight);
    return cpoint(x, y, gridPoint.getC());
}

const std::vector<std::vector<cpoint>>& MapGrid::getGrid() const {
    return grid;
}

float MapGrid::getCellWidth() const {
    return cellWidth;
}

float MapGrid::getCellHeight() const {
    return cellHeight;
}
