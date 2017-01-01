/*
 * ShiftRegisterArray.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: alex
 */

#include <hal/ShiftRegisterArray.h>

ShiftRegisterArray::ShiftRegisterArray(AccessPoint* clk) :
		ShiftRegister(clk) {
}

ShiftRegisterArray::~ShiftRegisterArray() {
}

void ShiftRegisterArray::push(uint8_t* values) {
	for(int i = 0; i < 8; i++){
		clkLow();
		for(unsigned int regNum = 0; regNum < registers_.size(); regNum++){
			registers_[regNum]->push(((values[regNum] >> i) & 0x01) != 0);
		}
		clkHigh();
	}
}

void ShiftRegisterArray::addShiftRegister(ShiftRegister* shiftRegister){
	registers_.push_back(shiftRegister);
}

ShiftRegister* ShiftRegisterArray::getShiftRegisterAt(int index){
	return registers_[index];
}

void ShiftRegisterArray::begin(void){
	clkLow();
}

void ShiftRegisterArray::end(void){
	clkHigh();
}

