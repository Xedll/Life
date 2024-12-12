#include <iostream>
#include "Menu.h"
#include <chrono>
int main()
{
	int width;
	int height;
	std::chrono::milliseconds interval{ 250 };
	bool sizeEntered = false; 
	while (!sizeEntered) {
		std::cout << "Enter width of game from 0 to 64: ";
		std::cin >> width;
		std::cout << "Enter height of game from 0 to 64: ";
		std::cin >> height; 
		if (width > 64 || height > 64 || width < 0 || height < 0) {
			std::cout << "Max size of the game is 64x64"<<std::endl;
		}
		else {
			sizeEntered = true;
		}
	}
	Menu* MainGame = new Menu(height, width, interval);
	MainGame->Create();
	std::getchar();
}
