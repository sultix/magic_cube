/*
 * Cube.h
 *
 *  Created on: Dec 30, 2016
 *      Author: alex
 */

#ifndef CUBE_CUBE_H_
#define CUBE_CUBE_H_

#include <vector>
#include "cube/Floor.h"
#include "frames/Frame.h"
#include "frames/FloorRegister.h"
#include "XObject.h"

class Cube : public XObject{
public:
	Cube();
	virtual ~Cube();

	void addFloor(Floor* floor);
	Floor* getFloor(unsigned int index);

	void play(std::vector<Frame*> frames);
	void playSymbol(Frame* frame, int reg, int shift);
	void play(Frame* frame);
	void off();

private:
	std::vector<Floor*> floors_;
};

#endif /* CUBE_CUBE_H_ */
