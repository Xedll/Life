#include <iostream>
#include "Menu.h"
#include <chrono>
#include <string>
int main()
{
	int width;
	int height;
	std::chrono::milliseconds interval{ 250 };
	bool sizeEntered = false; 
	std::string input;
	do {
		while (!sizeEntered) {
			std::cout << "Enter width of game from 0 to 64: ";
			std::cin >> width;
			std::cout << "Enter height of game from 0 to 64: ";
			std::cin >> height;
			if (width > 64 || height > 64 || width < 0 || height < 0) {
				std::cout << "Max size of the game is 64x64" << std::endl;
			}
			else {
				sizeEntered = true;
			}
		}
		Menu* MainGame = new Menu(height, width, interval);
		MainGame->Create();
		std::cout << "(Enter 'exit' to quit)" << std::endl;
	} while (std::cin >> input && input != "exit");
	
}
