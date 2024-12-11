#pragma once
#include <iostream>
#include <vector>
#include "Dot.h"
#include <thread>
#include <chrono>
struct Change
{
	Dot* Dot;
	int index;
};

class GameWindow
{
public:
	bool isRunning;
	int width;
	int height;
	GameWindow() : height(8), width(16), isRunning(true), _Interval(250) {
		_SetupMatrix();
	}
	GameWindow(int height, int width, std::chrono::milliseconds Interval) : height(height), width(width), isRunning(true), _Interval(Interval){
		_SetupMatrix();
	}
	
	inline void AddDot(int x,int y) {
		_Dots.push_back(new Dot(x, y, _matrix));
		_matrix.at(y).at(x) = true;
	}
	inline void DeleteDot(Dot* dot, int index) {
		_matrix.at(dot->y).at(dot->x) = false;
		_Dots.erase(_Dots.begin() + index);
	}
	inline void Show() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (_matrix[i][j]) {
					std::cout << '@';
				}
				else {
					std::cout << '-';
				}
			}
			std::cout << std::endl;
		}
		_UpdateMatrix();
	}
	inline void Run() {
		while (isRunning) {
			if (_Dots.size() == 0) {
				isRunning = false;
			}
			system("CLS");
			Show();
			std::this_thread::sleep_for(_Interval);

		}
	}
private:
	inline void _SetupMatrix() {
		for (int i = 0; i < height; i++) {
			_matrix.push_back(std::vector<bool>{});
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				_matrix[i].push_back(false);
			}
		}
		AddDot(3, 3);
		AddDot(3, 4);
		AddDot(3, 5);
		AddDot(2, 5);
		AddDot(1, 4);
	}
	inline void _UpdateMatrix(){
		std::vector<Change> forDelete;
		std::vector<std::vector<int>> forCreate;
		for (int i = 0; i < _Dots.size();i++) {
			if (!_Dots[i]->checkLife()) { //Death
				forDelete.push_back(Change{ _Dots[i], i});
			}
		}
		for (int i = 0; i < height; i++) { //Birth
			for (int j = 0; j < width; j++) {
				Dot dot(j, i, _matrix);
				dot.life = false;
				if (dot.checkLife()) {
					forCreate.push_back({ j , i });
				}
			}
		}
		for (int i = forDelete.size() - 1; i >= 0; i--) {
			DeleteDot(forDelete[i].Dot, forDelete[i].index);
		}
		for (int i = forCreate.size() - 1; i >= 0; i--) {
			AddDot(forCreate[i][0], forCreate[i][1]);
		}
	}
	std::vector<std::vector<bool>> _matrix;
	std::vector<Dot*> _Dots;
	std::chrono::milliseconds _Interval;
};

