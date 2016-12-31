/*
 * ShiftRegister.h
 *
 */

#ifndef HAL_SHIFTREGISTER_H_
#define HAL_SHIFTREGISTER_H_

#include <stdint.h>
#include "xmc_gpio.h"
#include "declarations.h"

#define DELAY_MS_LENGTH 32000

#define CLK_PORT PORT0->OUT

class ShiftRegister {
public:
	ShiftRegister(AccessPoint* clk);
	ShiftRegister(AccessPoint* clk, AccessPoint* data);
	virtual ~ShiftRegister();

	virtual void push(uint8_t value);
	virtual void push(bool value);

	virtual void cpush(uint8_t value);
	virtual void cpush(bool value);

	volatile uint32_t* getDataPort();
	uint32_t getDataPin();

protected:
	void clkHigh();
	void clkLow();
	volatile void delay_1ms(void);
	void delay(unsigned len);

	AccessPoint* clk_;
	AccessPoint* data_;
};

#endif /* HAL_SHIFTREGISTER_H_ */
