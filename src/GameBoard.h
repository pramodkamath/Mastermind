/*
 * GameBoard.h
 *
 *  Created on: 6 Apr 2017
 *      Author: urquhart
 */

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

#include "Peg.h"
#include "Slot.h"

namespace std {

class GameBoard {
public:
	GameBoard(int);
	virtual ~GameBoard();
	bool generateCode();
	Slot* getCodeSlot();
	bool addGuess(Slot*);
	int getSlotsFilled();
	bool generateFeedback(Slot*);
	void printBoard();
private:
	Slot* codeSlot;
	Slot* guessSlots;
	Slot* feedbackSlots;
	int slotsFilled;
};

} /* namespace std */

#endif /* GAMEBOARD_H_ */
