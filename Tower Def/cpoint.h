#ifndef CPOINT_H
#define CPOINT_H

class cpoint {
public:
	const static int map_row = 15;
	const static int map_col = 20;
	const static int Left = 3;
	const static int Top = 3;
private:
	int x, y, c;
public:
	cpoint() : x(0), y(0), c(0) {}
	cpoint(int x, int y, int c);
	int getX() {
		return this->x;
	}
	int getY() {
		return this->y;
	}
	int getC() {
		return this->c;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	void setC(int c) {
		this->c = c;
	}
};

#endif