/*
 * GameController.h
 *
 *  Created on: 6 Apr 2017
 *      Author: urquhart
 */

#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_

#include "GameBoard.h"
#include "Slot.h"

namespace std {

class GameController {
public:
	GameController();
	virtual ~GameController();
	void StartGame();
	void EndGame();
	Slot* getInput();

private:
	GameBoard* gameboard;
	bool gameWon;
};

} /* namespace std */

#endif /* GAMECONTROLLER_H_ */
