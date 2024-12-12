#include "GameWindow.h"
GameWindow::GameWindow() : p_height(8), p_width(16), p_isRunning(true), _Interval(250) {_SetupMatrix();}
GameWindow::GameWindow(int height, int width, std::chrono::milliseconds Interval) :p_height(height), p_width(width), p_isRunning(true), _Interval(Interval) { _SetupMatrix(); }

void GameWindow::AddDot(int x, int y) {
	_Dots.push_back(new Dot(x, y, _Matrix));
	_Matrix.at(y).at(x) = true;
}
void GameWindow::DeleteDot(int x, int y, int index) {
	_Matrix.at(y).at(x) = false;
	_Dots.erase(_Dots.begin() + index);
}
void GameWindow::Show() {
	for (int i = 0; i < p_height; i++) {
		for (int j = 0; j < p_width; j++) {
			if (_Matrix[i][j]) {
				std::cout << '@';
			}
			else {
				std::cout << '-';
			}
		}
		std::cout << " | " << i << " "<<std::endl;
	}
}
void GameWindow::Run() {
	while (p_isRunning) {
		if (_Dots.size() == 0) {
			p_isRunning = false;
		}
		system("CLS");
		Show();
		_UpdateMatrix();
		std::this_thread::sleep_for(_Interval);
	}
}
void GameWindow::_SetupMatrix() {
	for (int i = 0; i < p_height; i++) {
		_Matrix.push_back(std::vector<bool>{});
	}
	for (int i = 0; i < p_height; i++) {
		for (int j = 0; j < p_width; j++) {
			_Matrix[i].push_back(false);
		}
	}
}
void GameWindow::_UpdateMatrix() {
	std::vector<Change> forDelete;
	std::vector<std::vector<int>> forCreate;
	for (int i = 0; i < _Dots.size(); i++) {
		if (!_Dots[i]->checkLife()) { //Death
			forDelete.push_back(Change{ *_Dots[i], i });
		}
	}
	for (int i = 0; i < p_height; i++) { //Birth
		for (int j = 0; j < p_width; j++) {
			Dot dot(j, i, _Matrix);
			dot.p_alive = false;
			if (dot.checkLife()) {
				forCreate.push_back({ j , i });
			}
		}
	}
	for (int i = forDelete.size() - 1; i >= 0; i--) {
		DeleteDot(forDelete[i].Dot.p_x, forDelete[i].Dot.p_y , forDelete[i].index);
	}
	for (int i = forCreate.size() - 1; i >= 0; i--) {
		AddDot(forCreate[i][0], forCreate[i][1]);
	}
}

int GameWindow::CheckDot(int x, int y) {
	int find = -1;
	for (int i = 0; i < _Dots.size();i++) {
		if ((x == (*_Dots[i]).p_x) && (y == (*_Dots[i]).p_y)) {
			find = i;
		}
	}
	return find;
}