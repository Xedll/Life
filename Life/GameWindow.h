#pragma once
#include <iostream>
#include <vector>
#include "Dot.h"
#include <string>
#include <algorithm>

struct Change
{
	Dot* Dot;
	int index;
};
class GameWindow
{
public:
	int width;
	int height;
	std::vector<std::vector<bool>> matrix;
	std::vector<Dot*> Dots;
	GameWindow() {
		this->height = 8;
		this->width = 16;
		for (int i = 0; i < height; i++) {
			matrix.push_back(std::vector<bool>{});
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
					matrix[i].push_back(false);
			}
		}
		AddDot(3, 1);
		AddDot(3, 2);
		AddDot(3, 3);
		AddDot(4, 3);
		AddDot(5, 2);
	}

	void AddDot(int x,int y) {
		Dots.push_back(new Dot(x, y, matrix));
		matrix.at(y).at(x) = true;
	}
	void DeleteDot(Dot* dot, int index) {
		matrix.at(dot->y).at(dot->x) = false;
		Dots.erase(Dots.begin() + index);
	}
	void Show() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (matrix[i][j]) {
					std::cout<<'@';
				}
				else {
					std::cout << '#';
				}
			}
			std::cout << std::endl;
		}
	}
//private:
	void UpdateMatrix(){
		std::vector<Change> forDelete;
		std::vector<std::vector<int>> forCreate;
		for (int i = 0; i < Dots.size();i++) {
			if (!Dots[i]->checkLife()) { //Death
				forDelete.push_back(Change{Dots[i], i});
				//matrix[Dots[i]->y][Dots[i]->x] = false;
				//Dots.erase(Dots.begin() + i);
			}
		}
		for (int i = 1; i < height-1; i++) {
			for (int j = 1; j < width-1; j++) {
				Dot dot(j, i, matrix);
				dot.life = false;
				if (dot.checkLife()) {
					forCreate.push_back({ j , i });
				}
			}
		}
		for (int i = forDelete.size()-1; i >= 0; i--) {
			DeleteDot(forDelete[i].Dot, forDelete[i].index);
		}for (int i = forCreate.size() - 1; i >= 0; i--) {
			AddDot(forCreate[i][0], forCreate[i][1]);
		}
		Show();
	}
	
};

