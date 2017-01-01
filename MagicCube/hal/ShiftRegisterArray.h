/*
 * ShiftRegisterArray.h
 *
 *  Created on: Dec 30, 2016
 *      Author: alex
 */

#ifndef HAL_SHIFTREGISTERARRAY_H_
#define HAL_SHIFTREGISTERARRAY_H_

#include <vector>
#include "hal/ShiftRegister.h"

class ShiftRegisterArray : public ShiftRegister {
public:
	ShiftRegisterArray(AccessPoint* clk);
	virtual ~ShiftRegisterArray();

	void addShiftRegister(ShiftRegister* shiftRegister);
	virtual void push(uint8_t* values);

	void begin(void);
	void end(void);

private:
	std::vector<ShiftRegister*> registers_;
};

#endif /* HAL_SHIFTREGISTERARRAY_H_ */
