//============================================================================
// Name        : Mastermind.cpp
// Author      : PramodKamath
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "GameController.h"

using namespace std;

int main() {
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	std::cout << termcolor::red << "Hello, Colorful World!" << std::endl;
//	cout << red<<"▓" << endl; // prints !!!Hello World!!!
//	cout << "\033[2J\033[1;1H";

	GameController* gameController = new GameController();
	gameController->StartGame();
	gameController->EndGame();
	delete gameController;
	gameController = 0;
	return 0;
}
