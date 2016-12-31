/*
 * ShiftRegister.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: alex
 */

#include <hal/ShiftRegister.h>

ShiftRegister::ShiftRegister(AccessPoint* clk) : clk_(clk) {
}

ShiftRegister::ShiftRegister(AccessPoint* clk, AccessPoint* data) : clk_(clk), data_(data) {
}

ShiftRegister::~ShiftRegister() {
}

void ShiftRegister::push(uint8_t value){
	for(int i = 0; i < 8; i++){
		push(((value >> i) & 0x01) == 0);
	}
}

void ShiftRegister::push(bool value){
	if(value){
		SET_BIT(*data_->port, data_->pin);
	} else {
		CLR_BIT(*data_->port, data_->pin);
	}
}

void ShiftRegister::cpush(uint8_t value){
	for(int i = 0; i < 8; i++){
		cpush(((value >> i) & 0x01) == 0);
	}
}

void ShiftRegister::cpush(bool value){
	clkLow();
	push(value);
	clkHigh();
}

void ShiftRegister::clkHigh(void){
	SET_BIT(PORT1->OUT, 0);
	delay(DELAY_TIME);
	CLR_BIT(PORT1->OUT, 0);

	SET_BIT(*clk_->port,clk_->pin);

	delay(DELAY_TIME);
}

void ShiftRegister::clkLow(void){
	delay(DELAY_TIME);
	CLR_BIT(*clk_->port,clk_->pin);
	delay(DELAY_TIME);
}

volatile uint32_t* ShiftRegister::getDataPort(void){
	return data_->port;
}

uint32_t ShiftRegister::getDataPin(void){
	return data_->pin;
}


volatile void ShiftRegister::delay_1ms(void){
	for(int i= 0; i < DELAY_MS_LENGTH * 100; i++){
	}
}

void ShiftRegister::delay(unsigned len)
{
	while(len--);
}
