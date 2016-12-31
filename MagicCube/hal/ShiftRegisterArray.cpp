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

void ShiftRegisterArray::push(uint8_t value) {
	for(int i = 0; i < 8; i++){
		clkLow();
		for(unsigned int regNum = 0; regNum < registers_.size(); regNum++){
			registers_[regNum]->push(((value >> i) & 0x01) == 0);
		}
		clkHigh();
	}
}

void ShiftRegisterArray::addShiftRegister(ShiftRegister* shiftRegister){
	registers_.push_back(shiftRegister);
}

void ShiftRegisterArray::begin(void){
	clkLow();
}

void ShiftRegisterArray::end(void){
	clkHigh();
}

