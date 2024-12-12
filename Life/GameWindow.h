#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "Dot.h"

struct Change
{
	Dot Dot;
	int index;
};

class GameWindow
{
public:
	bool p_isRunning;
	int p_width;
	int p_height;

	GameWindow();
	GameWindow(int height, int width, std::chrono::milliseconds Interval);
	
	void AddDot(int x, int y);
	void DeleteDot(int x, int y, int index);
	void Show();
	void Run();
	int CheckDot(int x, int y);
private:
	std::vector<std::vector<bool>> _Matrix;
	std::vector<Dot*> _Dots;
	std::chrono::milliseconds _Interval;

	void _SetupMatrix();
	void _UpdateMatrix();
};