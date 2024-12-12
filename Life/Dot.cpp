#include "Dot.h"
Dot::Dot(int x, int y, std::vector<std::vector<bool>>& matrix) : p_matrix(matrix), p_x(x), p_y(y), p_alive(true) {}


bool Dot::checkLife() {
	if (p_alive == false && _getNeighbors() == 3) {
		p_alive = true;
	}
	else if (p_alive == true && (_getNeighbors() < 2 || _getNeighbors() > 3)) {
		p_alive = false;
	}
	return p_alive;
}
int Dot::_getNeighbors() {
	int count = 0;
	if (p_matrix.at(p_y == p_matrix.size() - 1 ? 0 : p_y + 1).at(p_x == p_matrix[0].size() - 1 ? 0 : p_x + 1) == true) { count++; }
	if (p_matrix.at(p_y == 0 ? p_matrix.size() - 1 : p_y - 1).at(p_x == 0 ? p_matrix[0].size() - 1 : p_x - 1) == true) { count++; }
	if (p_matrix.at(p_y == p_matrix.size() - 1 ? 0 : p_y + 1).at(p_x == 0 ? p_matrix[0].size() - 1 : p_x - 1) == true) { count++; }
	if (p_matrix.at(p_y == 0 ? p_matrix.size() - 1 : p_y - 1).at(p_x == p_matrix[0].size() - 1 ? 0 : p_x + 1) == true) { count++; }
	if (p_matrix.at(p_y).at(p_x == p_matrix[0].size() - 1 ? 0 : p_x + 1) == true) { count++; }
	if (p_matrix.at(p_y).at(p_x == 0 ? p_matrix[0].size() - 1 : p_x - 1) == true) { count++; }
	if (p_matrix.at(p_y == p_matrix.size() - 1 ? 0 : p_y + 1).at(p_x) == true) { count++; }
	if (p_matrix.at(p_y == 0 ? p_matrix.size() - 1 : p_y - 1).at(p_x) == true) { count++; }
	return count;
}