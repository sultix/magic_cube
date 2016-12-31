/*
 * PinBase.cpp
 *
 */

#include <hal/PinBase.h>

PinBase::PinBase(volatile uint32_t* port, uint32_t pin) : port_(port), pin_(pin) {

}

PinBase::~PinBase() {
}

void PinBase::high(){
	SET_BIT(*port_, pin_);
}

void PinBase::low(){
	CLR_BIT(*port_, pin_);
}

