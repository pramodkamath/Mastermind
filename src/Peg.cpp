/*
 * Peg.cpp
 *
 *  Created on: 6 Apr 2017
 *      Author: urquhart
 */

#include "Peg.h"
#include <iostream>
#include "termcolor.hpp"

using namespace std;
using namespace termcolor;

Peg::Peg(): pegColour(NONE){
}

Peg::~Peg() {
	// TODO Auto-generated destructor stub

}

Colour Peg::getPegColour() {
		return pegColour;
}

void Peg::setPegColour(Colour pegColour) {
		this->pegColour = pegColour;
}

bool Peg::operator ==(Peg &a) {
	if(this->pegColour == a.getPegColour()){
		return true;
	}
	return false;
}

void Peg::printPeg() {
	switch (this->pegColour) {
		case RED:
			cout << red << "R";
			break;
		case BLUE:
			cout << blue << "B";
			break;
		case GREEN:
			cout << green << "G";
			break;
		case YELLOW:
			cout << yellow << "Y";
			break;
		case MAGENTA:
			cout << magenta << "M";
			break;
		case CYAN:
			cout << cyan << "C";
			break;
		case GREY:
			cout << grey << "G";
			break;
		case WHITE:
			cout << white << "W";
			break;
		default:
			break;
	}
}

Peg& Peg::operator =(Peg *a) {
	this->setPegColour(a->getPegColour());
	return *this;
}
