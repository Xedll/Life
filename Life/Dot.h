#include <vector>
#include <iostream>
#pragma once
class Dot
{
public:
	int x;
	int y;
	bool life;
	std::vector<std::vector<bool>> &matrix;
	Dot(int x, int y, std::vector<std::vector<bool>>& matrix) : matrix(matrix), x(x), y(y), life(true) {}
	bool checkLife() {
		if (life == false && getNeighbors() == 3) {
			life = true;
		}
		else if (life == true && (getNeighbors() < 2 || getNeighbors() > 3)) {
			life = false;
		}
		return life;
	}
	int getNeighbors() {
		int count = 0;
		if ((&matrix)->at(y + 1).at(x + 1) == true) { count++; }
		if ((&matrix)->at(y - 1).at(x - 1) == true) { count++; }
		if ((&matrix)->at(y + 1).at(x - 1) == true) { count++; }
		if ((&matrix)->at(y - 1).at(x + 1) == true) { count++; }
		if ((&matrix)->at(y).at(x + 1) == true) { count++; }
		if ((&matrix)->at(y).at(x - 1) == true) { count++; }
		if ((&matrix)->at(y + 1).at(x) == true) { count++; }
		if ((&matrix)->at(y - 1).at(x) == true) { count++; }
		return count;
	}
};

