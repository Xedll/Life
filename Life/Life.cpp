#include <iostream>
#include "GameWindow.h"
int main()
{

	GameWindow* test = new GameWindow();
	test->Show();
	std::cout << std::endl;
	test->UpdateMatrix();
	std::cout <<std::endl;
	test->UpdateMatrix();
	std::cout << std::endl;
	test->UpdateMatrix();
	std::cout << std::endl;
	test->UpdateMatrix();
}
