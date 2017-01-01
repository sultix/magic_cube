/*
 * Cube.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: alex
 */

#include <cube/Cube.h>

#define LAYER_Y_1_BITMASK 0xF
#define LAYER_Y_2_BITMASK 0xF0
#define SYMBOL_SHOW_DELAY 10

Cube::Cube() {
}

Cube::~Cube() {
}

void Cube::addFloor(Floor* floor){
	floors_.push_back(floor);
}

Floor* Cube::getFloor(unsigned int index){
	return floors_[index];
}

void Cube::off(){
	for(unsigned int i = 0; i< floors_.size(); i++){
		floors_[i]->off();
	}
}

void Cube::playSymbol(Frame* frame, int reg, int shift = 0){
	for(int floorIndex = 0; floorIndex <= frame->getFloorsCount() - 1; floorIndex++){
		Floor* floor = floors_[floorIndex];

		floor->off();
		floor->begin();

		uint8_t arg[2] = {0x00,0x00};

		if(reg == 2){
			arg[0] = (frame->getValue(floorIndex) & LAYER_Y_1_BITMASK ) >> shift;
			arg[1] = (frame->getValue(floorIndex) & LAYER_Y_2_BITMASK) >> shift;
		}else{
			arg[reg] = frame->getValue(floorIndex) >> shift;
		}

		floor->push(arg);
		floor->end();
		floor->on();
		delay(150000 / 65);
		floor->off();
	}
}

void Cube::play(Frame* frame){
	while(1U){

		for(int i= 0; i < SYMBOL_SHOW_DELAY; i++){
			playSymbol(frame, 0);
		}

		off();
		delay(1000);

		for(int i= 0; i < SYMBOL_SHOW_DELAY; i++){
			playSymbol(frame, 2);
		}

		off();
		delay(1000);

		for(int i= 0; i < SYMBOL_SHOW_DELAY; i++){
			playSymbol(frame, 1);
		}

		off();
		delay(1000);

		for(int i= 0; i < SYMBOL_SHOW_DELAY; i++){
			playSymbol(frame, 2);
		}
	}
}

void Cube::play(std::vector<Frame*> frames){
	while (1U) {
		for(unsigned int i = 0; i < frames.size(); i++){
			play(frames[i]);
		}
	}

}
