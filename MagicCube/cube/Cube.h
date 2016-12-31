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

	void play(std::vector<Frame*> frames);
	void play(Floor* floor, FloorRegister* reg);
	void play(Frame* frame);

private:
	std::vector<Floor*> floors_;
};

#endif /* CUBE_CUBE_H_ */
