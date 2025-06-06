#ifndef MAPGRID_H
#define MAPGRID_H

#include <vector>
#include "cpoint.h"

class MapGrid {
private:
    std::vector<std::vector<cpoint>> grid;
    static float cellWidth;
    static float cellHeight;
    unsigned int rows;
    unsigned int cols;

public:
    MapGrid(unsigned int rows, unsigned int cols);
    void initializeGrid(int screenWidth, int screenHeight);

    static cpoint XYtoRC(cpoint pixel);
    static cpoint RCtoXY(cpoint grid);

    const std::vector<std::vector<cpoint>>& getGrid() const;
    float getCellWidth() const;
    float getCellHeight() const;
};

#endif
