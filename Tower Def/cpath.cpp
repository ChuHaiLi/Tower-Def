#include "cpath.h"
#include "cpoint.h"
#include<iostream>
#include<fstream>

using namespace std;

bool cpath::loadFromFile(const string& filename) {
	ifstream in(filename);
	if (!in.is_open()) return false;

	_waypoints.clear();

	int row, col;
	while (in >> row >> col) {
		_waypoints.push_back(cpoint(row, col, 0));
	}

	return !_waypoints.empty();
}

void cpath::addPoint(const cpoint& point) {
	_waypoints.push_back(point);
}

const vector<cpoint>& cpath::getWaypoints() const{
	return _waypoints;
}

int cpath::getSize() const {
	return _waypoints.size();
}