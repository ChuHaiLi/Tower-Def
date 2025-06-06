#ifndef CPATH_H
#define CPATH_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "cpoint.h"

using namespace std;

class cpath {
private:
    vector<cpoint> _waypoints;
public:
    cpath() = default;
    bool loadFromFile(const string& filename);
    void addPoint(const cpoint& point);
    const vector<cpoint>& getWaypoints() const;
    int getSize() const;
};

#endif