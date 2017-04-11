/*
 * Slot.h
 *
 *  Created on: 6 Apr 2017
 *      Author: urquhart
 */

#ifndef SLOT_H_
#define SLOT_H_

#include <string>
#include "Peg.h"

namespace std {

class Slot {
public:
	Slot();
	virtual ~Slot();
	Peg* getPegs();
	bool setPegs(Peg[4]);
	bool operator==(Slot &a);
	Slot& operator=(Slot*);
private:
	Peg* pegs;
};

} /* namespace std */

#endif /* SLOT_H_ */
