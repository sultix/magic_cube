/*
 * PinBase.h
 *
 *  Created on: Dec 30, 2016
 *      Author: alex
 */

#ifndef HAL_PINBASE_H_
#define HAL_PINBASE_H_

#include <stdint.h>
#include "xmc_gpio.h"

class PinBase {
public:
	PinBase(volatile uint32_t* port, uint32_t pin);
	virtual ~PinBase();

	void high();
	void low();

protected:
	volatile uint32_t* port_;
	uint32_t pin_;
};

#endif /* HAL_PINBASE_H_ */
