/*
 * Cube.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: alex
 */

#include <cube/Cube.h>

Cube::Cube() {
}

Cube::~Cube() {
}

void Cube::addFloor(Floor* floor){
	floors_.push_back(floor);
}

void Cube::play(Floor* floor, FloorRegister* reg){
	for(unsigned int i = 0; i < reg->count(); i++){
		floor->begin();
		//floor->push(reg->getValue(i));
		floor->end();
	}
}

void Cube::play(Frame* frame){
	do{
		for(unsigned int floorIndex = 0; floorIndex < frame->getFloorsCount(); floorIndex++){
			FloorRegister* reg = frame->getFloorData(floorIndex);
			Floor* floor = floors_[floorIndex];
			play(floor, reg);
		}

		delay(100000);
	}while(1U);
}

void Cube::play(std::vector<Frame*> frames){
	while (1U) {
		for(unsigned int i = 0; i < frames.size(); i++){
			play(frames[i]);
		}
	}

}
