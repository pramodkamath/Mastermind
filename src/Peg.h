/*
 * Peg.h
 *
 *  Created on: 6 Apr 2017
 *      Author: urquhart
 */

#ifndef PEG_H_
#define PEG_H_

namespace std {

enum Colour{
	RED,
	BLUE,
	GREEN,
	YELLOW,
	MAGENTA,
	CYAN,
	GREY,
	WHITE,
	NONE
};

class Peg {
public:
	Peg();
	virtual ~Peg();
	Colour getPegColour();
	void setPegColour(Colour pegColour);
	void printPeg();
	bool operator==(Peg &a );
	Peg& operator=(Peg *a);

private:
	Colour pegColour;
};

} /* namespace std */

#endif /* PEG_H_ */
