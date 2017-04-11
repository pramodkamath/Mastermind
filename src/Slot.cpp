/*
 * Slot.cpp
 *
 *  Created on: 6 Apr 2017
 *      Author: urquhart
 */

#include "Slot.h"
#include "Peg.h"

namespace std {

Slot::Slot() {
	// TODO Auto-generated constructor stub
	this->pegs = new Peg[4];
}

Slot::~Slot() {
	// TODO Auto-generated destructor stub
	delete[] pegs;
	pegs = 0;
}

Peg* Slot::getPegs() {
	return pegs;
}

bool Slot::setPegs(Peg input[4]) {
	for(int i = 0; i < 4; i++){
		pegs[i].setPegColour(input[i].getPegColour());
	}
	return true;
}

bool Slot::operator==(Slot &a){
	bool result = true;
	Peg* aPegs = a.getPegs();
	for(int i = 0; i < 4; i++){
		if(pegs[i].getPegColour() != aPegs[i].getPegColour()){
			result = false;
			break;
		}
	}
	return result;
}

Slot& Slot::operator =(Slot *a) {
	for(int i = 0; i <4; i++){
		pegs[i] = (a->getPegs())[i];
	}
	return *this;
}

} /* namespace std */
