#pragma once
#include <vector>
#include <iostream>
class Dot
{
public:
	int p_x;
	int p_y;
	bool p_alive;
	std::vector<std::vector<bool>> &p_matrix;
	Dot(int x, int y, std::vector<std::vector<bool>> &matrix);
	bool checkLife();
private:
	int _getNeighbors();
};

