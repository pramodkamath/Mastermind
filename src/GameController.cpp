/*
 * GameController.cpp
 *
 *  Created on: 6 Apr 2017
 *      Author: urquhart
 */
#include <iostream>
#include <string>
#include "GameController.h"
#include "GameBoard.h"
#include "termcolor.hpp"

using namespace std;
using namespace termcolor;

GameController::GameController() {
	// TODO Auto-generated constructor stub
	gameboard = 0;
	gameWon = false;
}

GameController::~GameController() {
	// TODO Auto-generated destructor stub
	delete gameboard;
	gameboard = 0;
}

void GameController::StartGame() {

	int slots = 0;
	cout<< white <<"Enter Number of Turns to Crack the Code (maximum: 12):\n";
	cin>>slots;
	while(cin.fail() || slots <= 0 || slots > 12){
		cin.clear();
		cin.ignore(cin.gcount()+1,'\n');
		cout << white << "Bad entry. Enter Number of Turns to Crack the Code (maximum: 12):\n";
		cin >> slots;
	}
	gameboard = new GameBoard(slots);
	gameboard->generateCode();


	while((gameboard->getSlotsFilled()) < slots && gameWon == false){
		Slot* userguess = getInput();

		if(userguess != 0){
			if(*userguess == *(gameboard->getCodeSlot())){
				gameWon = true;
			}
			else {
				gameboard->addGuess(userguess);
			}
			delete userguess;
			userguess = 0;
			cout << "\033[2J\033[1;1H";
			gameboard->printBoard();
		}
		else {
			cout << white << "Bad entry." << endl;
		}
	}
}

void GameController::EndGame() {
	if(gameWon == false){
		cout << white << "Sorry! you lost!\n\nThe code is: ";
		Slot* codeSlot = gameboard->getCodeSlot();
		for(int i = 0; i < 4; i++){
			(codeSlot->getPegs())[i].printPeg();
		}
		cout<<endl;
	}
	else {
		cout << white << "Congratulations! You have cracked the code. You are a Mastermind!"<<endl;;
	}
}

Slot* GameController::getInput() {
	string input;
	cout << white << "The code is a combination of 4 of the following colours:"<<endl;
	cout << red << "R - Red" << endl;
	cout << blue << "B - Blue" << endl;
	cout << green << "G - Green" << endl;
	cout << yellow << "Y - Yellow" << endl;
	cout << magenta << "M - Magenta" << endl;
	cout << cyan << "C - Cyan" << endl;
	cout << white << "The feedbacks received will be in following two colours: "<< endl;
	cout << grey << "G - Grey (For every code guessed in the correct position)" << endl;
	cout << white << "W - White (For every code color guessed correctly)" << endl;

	cout << white <<"Enter your Guess:\n";
	cin >> input;
	while(cin.fail() || input.length() < 4){
		cin.clear();
		cin.ignore(cin.gcount()+1,'\n');
		cout << white <<"Bad entry. Enter your Guess:\n";
		cin >> input;
	}
	Slot* inputSlot = new Slot();
	Peg* pegs = inputSlot->getPegs();
	for(int i = 0; i < 4; i++){
		switch (input[i]) {
			case 'R':
			case 'r':
				pegs[i].setPegColour(RED);
				break;
			case 'B':
			case 'b':
				pegs[i].setPegColour(BLUE);
				break;
			case 'G':
			case 'g':
				pegs[i].setPegColour(GREEN);
				break;
			case 'Y':
			case 'y':
				pegs[i].setPegColour(YELLOW);
				break;
			case 'M':
			case 'm':
				pegs[i].setPegColour(MAGENTA);
				break;
			case 'C':
			case 'c':
				pegs[i].setPegColour(CYAN);
				break;
			default:
				delete inputSlot;
				inputSlot = 0;
				return inputSlot;
		}
	}
	return inputSlot;
}
