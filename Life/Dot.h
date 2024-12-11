#include <vector>
#include <iostream>
#pragma once
class Dot
{
public:
	int x;
	int y;
	bool alive;
	std::vector<std::vector<bool>> &matrix;
	Dot(int x, int y, std::vector<std::vector<bool>>& matrix) : matrix(matrix), x(x), y(y), alive(true) {}
	inline bool checkLife() {
		if (alive == false && getNeighbors() == 3) {
			alive = true;
		}
		else if (alive == true && (getNeighbors() < 2 || getNeighbors() > 3)) {
			alive = false;
		}
		return alive;
	}
private:
	inline int getNeighbors() {
		int count = 0;
		if (matrix.at(y == matrix.size() - 1 ? 0 : y + 1).at(x == matrix[0].size() - 1 ? 0 : x + 1) == true) { count++; }
		if (matrix.at(y == 0 ? matrix.size() - 1 : y - 1).at(x == 0 ? matrix[0].size() - 1 : x - 1) == true) { count++; }
		if (matrix.at(y == matrix.size() - 1 ? 0 : y + 1).at(x == 0 ? matrix[0].size() - 1 : x - 1) == true) { count++; }
		if (matrix.at(y == 0 ? matrix.size() - 1 : y - 1).at(x == matrix[0].size() - 1 ? 0 : x + 1) == true) { count++; }
		if (matrix.at(y).at(x == matrix[0].size() - 1 ? 0 : x + 1) == true) { count++; }
		if (matrix.at(y).at(x == 0 ? matrix[0].size() - 1 : x - 1) == true) { count++; }
		if (matrix.at(y == matrix.size() - 1 ? 0 : y + 1).at(x) == true) { count++; }
		if (matrix.at(y == 0 ? matrix.size() - 1 : y - 1).at(x) == true) { count++; }
		return count;
	}
};

