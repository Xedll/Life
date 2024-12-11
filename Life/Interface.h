#pragma once
#include <iostream>
class GameWindow
{
public:
	int width;
	int height;
	GameWindow() {
		this->height = 32;
		this->width = 32;
	}

	void Show() {
		for (int i = 0; i < this->height; i++) {
			for (int j = 0; j < this->width; j++) {
				std::cout << " 0 ";
			}
		}
	}
};

