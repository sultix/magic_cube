/*
 * Floor.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: alex
 */

#include <cube/Floor.h>

Floor::Floor(volatile uint32_t* port, uint32_t pin) : PinBase(port, pin) {
}

Floor::~Floor() {
}

void Floor::setRegisterArray(ShiftRegisterArray* shiftRegisterArray){
	shiftRegisterArray_ = shiftRegisterArray;
}

void Floor::on(void){
	high();
}

void Floor::off(void){
	low();
}

void Floor::push(uint8_t* values){
	shiftRegisterArray_->push(values);
}

void Floor::begin(void){
	off();
	shiftRegisterArray_->begin();
}

void Floor::end(void){
	shiftRegisterArray_->end();
	on();
}
