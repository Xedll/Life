#include "Menu.h"
#include "GameWindow.h"
#include <iostream>
Menu::Menu() :p_GameWindow(*(new GameWindow())), _Inputting(true), _commandType(-1), _xInput(-1), _yInput(-1) {};
Menu::Menu(int height, int width, std::chrono::milliseconds Interval) :p_GameWindow(*(new GameWindow(height, width,Interval))), _Inputting(true),_commandType(-1),_xInput(-1),_yInput(-1) {};

void Menu::Create() {
	p_GameWindow.Show();
	while (_Inputting) {
		std::cout << "Choose command: 1 - create dot, 2 - delete dot, 3 - start the game, 4 - leave" << std::endl;
		std::cin >> _commandType;
		switch (_commandType) {
			case 1:
				_CreateDot();
				break; 
			case 2:
				_DeleteDot();
				break;
			case 3:
				p_GameWindow.Run();
				break;
			case 4:
				std::cout << "Exiting..." << std::endl;
				_Inputting = false;
				break;
			default:
				std::cout << "This command does not exist." << std::endl;
				break;
		}
	}
}
void Menu::_CreateDot() {
	std::cout << "Enter x for Dot from 0 to " << p_GameWindow.p_width << " :";
	std::cin >> _xInput;
	std::cout << "Enter y for Dot from 0 to " << p_GameWindow.p_height << " :";
	std::cin >> _yInput;
	int findedIndex = p_GameWindow.CheckDot(_xInput, _yInput);
	if (findedIndex == -1) {
		p_GameWindow.AddDot(_xInput, _yInput);
		system("CLS");
		p_GameWindow.Show();
	}
	else {
		std::cout << "Dot with this coordinates already exists" << std::endl;
	}
}

void Menu::_DeleteDot() {
	std::cout << "Enter x for existing Dot from 0 to " << p_GameWindow.p_width << " :";
	std::cin >> _xInput;
	std::cout << "Enter y for existing Dot from 0 to " << p_GameWindow.p_height << " :";
	std::cin >> _yInput;
	int findedIndex = p_GameWindow.CheckDot(_xInput, _yInput);
	if (findedIndex != -1) {
		p_GameWindow.DeleteDot(_xInput, _yInput, findedIndex);
		system("CLS");
		p_GameWindow.Show();
	}
	else {
		std::cout << "Dot with this coordinates does not exist" << std::endl;
	}
}