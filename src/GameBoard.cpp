/*
 * GameBoard.cpp
 *
 *  Created on: 6 Apr 2017
 *      Author: urquhart
 */

#include "GameBoard.h"
#include <string.h>
#include <iostream>
#include "termcolor.hpp"
#include <stdlib.h>

using namespace std;
using namespace termcolor;

GameBoard::GameBoard(int slots){
	// TODO Auto-generated constructor stub
	codeSlot = new Slot();
	guessSlots = new Slot[slots];
	feedbackSlots = new Slot[slots];
	slotsFilled = 0;
}

GameBoard::~GameBoard() {
	// TODO Auto-generated destructor stub
	delete codeSlot;
	delete[] guessSlots;
	delete[] feedbackSlots;
	codeSlot = 0;
	guessSlots = 0;
	feedbackSlots = 0;
}

bool GameBoard::generateCode() {
	srand(time(NULL));
	Peg* codePegs = codeSlot->getPegs();
	for(int i = 0; i < 4; i++){
		Colour randomColour = static_cast<Colour>(rand()%6);
		if(randomColour >= 0 && randomColour < 6){
			codePegs[i].setPegColour(randomColour);
		}
		else
			return false;
	}
	return true;
}

Slot* GameBoard::getCodeSlot() {
	return codeSlot;
}

bool GameBoard::addGuess(Slot* guess) {

	guessSlots[slotsFilled] = guess;
	generateFeedback(guess);
	slotsFilled++;
	return true;
}

int GameBoard::getSlotsFilled() {
	return slotsFilled;
}

bool GameBoard::generateFeedback(Slot* guess) {
	Peg* guessPegs = guess->getPegs();
	Peg* codePegs = codeSlot->getPegs();
	int feedback = 0;
	for(int i = 0; i < 4; i++){
		if(guessPegs[i] == codePegs[i]){
			guessPegs[i].setPegColour(NONE);
			feedbackSlots[slotsFilled].getPegs()[feedback].setPegColour(GREY);
			feedback++;
		}
		else {
			for(int j = 0; j < 4; j++){
				if(i != j){
					if(codePegs[i] == guessPegs[j]){
						guessPegs[j].setPegColour(NONE);
						feedbackSlots[slotsFilled].getPegs()[feedback].setPegColour(WHITE);
						feedback++;
						break;
					}
				}
			}
		}
	}
	return true;
}

void GameBoard::printBoard() {
	cout<< white << "    MASTERMIND    "<<endl;
	cout<< white << "Guesses | Feedback"<<endl<<endl;
	for(int i = 0; i < slotsFilled; i++){
		for(int j = 0; j < 4; j++){
			(guessSlots[i].getPegs())[j].printPeg();
		}
		cout << white <<"    | ";
		for(int k = 0; k < 4; k++){
			(feedbackSlots[i].getPegs())[k].printPeg();
		}
		cout<<endl;
		cout << white << "-----------------" << endl;
	}
}

