/*
 * FloorRegister.cpp
 *
 *  Created on: Dec 31, 2016
 *      Author: alex
 */

#include <frames/FloorRegister.h>

FloorRegister::FloorRegister() {

}

FloorRegister::~FloorRegister() {
}

void FloorRegister::addValue(uint8_t value){
	values_.push_back(value);
}

uint8_t FloorRegister::getValue(int index){
	return values_[index];
}

unsigned int FloorRegister::count(void){
	return values_.size();
}

