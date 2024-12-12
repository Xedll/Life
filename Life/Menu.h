#pragma once
#include "GameWindow.h"

class Menu
{
public:
	Menu();
	Menu(int height, int width, std::chrono::milliseconds Interval);
	void Create();
private:
	int _xInput;
	int _yInput;
	int _commandType;
	bool _Inputting;
	void _CreateDot();
	void _DeleteDot();
	GameWindow& p_GameWindow;
};

