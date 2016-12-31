/*
 * Floor.h
 *
 *  Created on: Dec 30, 2016
 *      Author: alex
 */

#ifndef CUBE_FLOOR_H_
#define CUBE_FLOOR_H_

#include <vector>
#include "hal/PinBase.h"
#include "hal/ShiftRegister.h"
#include "hal/ShiftRegisterArray.h"
#include "XObject.h"

class Floor : public PinBase, public XObject {
public:
	Floor(volatile uint32_t* port, uint32_t pin);
	virtual ~Floor();

	void on(void);
	void off(void);

	void begin(void);
	void end(void);
	void push(uint8_t value);
	void setRegisterArray(ShiftRegisterArray* shiftRegisterArray);

private:
	ShiftRegisterArray* shiftRegisterArray_;
};

#endif /* CUBE_FLOOR_H_ */
