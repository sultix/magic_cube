/*
 * main.c
 *
 */

#include <DAVE.h>

#include <inttypes.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "xmc_gpio.h"

#include "hal/PinBase.h"
#include "hal/ShiftRegister.h"
#include "hal/ShiftRegisterArray.h"
#include "hal/GPIO.h"
#include "declarations.h"
#include "cube/Cube.h"
#include "cube/Floor.h"
#include "framesdata.h"

void delay(unsigned len) {
	while (len--)
		;
}

void initApplication() {

	// Clock configuration
	SCU_GENERAL->PASSWD = 0x000000C0UL; // disable bit protection
	SCU_CLK->CLKCR = 0x3FF00400UL; // MCLK = 8MHz, PCLK = 8MHz
	while ((SCU_CLK->CLKCR & SCU_CLK_CLKCR_VDDC2LOW_Msk))
		;
	SCU_GENERAL->PASSWD = 0x000000C3UL; // enable bit protection
	SystemCoreClockUpdate();

	// Konfiguriere Pin1.0 als Ausgang
	PORT1->IOCR0 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 0 * 8);//RED LED PIN 1.0
	PORT1->IOCR0 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 1 * 8);//RED LED PIN 1.1

	PORT2->IOCR8 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 2 * 8); //1 Floor PIN 2.10
	PORT2->IOCR8 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 3 * 8); //2 Floor PIN 2.11
	PORT0->IOCR4 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 2 * 8); //3 Floor PIN 0.6
	PORT0->IOCR4 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 3 * 8); //4 Floor PIN 0.7

	PORT0->IOCR0 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 0 * 8);	//DATA1 PIN 0.0
	PORT0->IOCR4 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 1 * 8);	//DATA2 PIN 0.5

	PORT0->IOCR8 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 1 * 8);	//CLK PIN 0.9
	PORT0->IOCR12 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 2 * 8);	//CLK PIN 0.14

	// Konfiguriere Pin1.15 als Eingang ohne PullUp
	//PORT1->IOCR12 |= (XMC_GPIO_MODE_INPUT_TRISTATE <<3*8);

	// SystemTimer auf 10ms konfigurieren
	SysTick_Config(SystemCoreClock / 100);

	P2_7_enable_digital();
	P2_9_enable_digital();
	P2_10_enable_digital();
	P2_11_enable_digital();

	CLR_BIT(PORT0->OUT, PIN_DATA_1);
	CLR_BIT(PORT0->OUT, PIN_DATA_2);
	CLR_BIT(PORT0->OUT, PIN_CLK);
	CLR_BIT(PORT0->OUT, PIN_VCC);

	CLR_BIT(PORT2->OUT, PIN_1_FLOOR);
	CLR_BIT(PORT2->OUT, PIN_2_FLOOR);
	CLR_BIT(PORT0->OUT, PIN_3_FLOOR);
	CLR_BIT(PORT0->OUT, PIN_4_FLOOR);

	delay(50000);
	SET_BIT(PORT0->OUT, PIN_VCC);
}

int main(void) {
	DAVE_STATUS_t status;

	status = DAVE_Init(); /* Initialization of DAVE APPs  */

	if (status != DAVE_STATUS_SUCCESS) {
		/* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
		XMC_DEBUG("DAVE APPs initialization failed\n");
		while (1U) {

		}
	}

	initApplication();

	//PinBase pin(&(PORT0->OUT), PIN_3_FLOOR);
	//pin.high();

	AccessPoint clk;
	clk.port = &PORT0->OUT;
	clk.pin = PIN_CLK;

	AccessPoint data1;
	data1.port = &PORT0->OUT;
	data1.pin = PIN_DATA_1;

	AccessPoint data2;
	data2.port = &PORT0->OUT;
	data2.pin = PIN_DATA_2;

	ShiftRegister shiftRegister1(&clk, &data1);
	ShiftRegister shiftRegister2(&clk, &data2);

	ShiftRegisterArray shiftRegisterArray(&clk);
	shiftRegisterArray.addShiftRegister(&shiftRegister1);
	shiftRegisterArray.addShiftRegister(&shiftRegister2);

	//Cube cube;

	Floor floor1(&PORT2->OUT, PIN_1_FLOOR);
	floor1.setRegisterArray(&shiftRegisterArray);

	Floor floor2(&PORT2->OUT, PIN_2_FLOOR);
	floor2.setRegisterArray(&shiftRegisterArray);

	Floor floor3(&PORT0->OUT, PIN_3_FLOOR);
	floor3.setRegisterArray(&shiftRegisterArray);

	Floor floor4(&PORT0->OUT, PIN_4_FLOOR);
	floor4.setRegisterArray(&shiftRegisterArray);

//	cube.addFloor(&floor1);
//	cube.addFloor(&floor2);
//	cube.addFloor(&floor3);
//	cube.addFloor(&floor4);

	//Frame frame;
	//frame.init(frameData);
	//cube.play(&frame);

	int i = 5;
	//int div = 1;
	uint8_t cntr1 = 0;
	uint8_t cntr2 = 0xFF;

	//uint8_t argArr[2] = { 0x00, 0x00 };
	Floor* curentFloor;
	while (1U) {
		i--; if(i==0) i=4;
		if (i == 1) {
			curentFloor = &floor1;
			//curentFloor->off();
			uint8_t argArr[2] = { cntr1, cntr2 };
			curentFloor->push(argArr);
			curentFloor->on();
		} else if (i == 2) {
			curentFloor = &floor2;
			//curentFloor->off();
			//uint8_t argArr[2] = { cntr2, cntr1 };
			uint8_t argArr[2] = { cntr1, cntr2 };
			curentFloor->push(argArr);
			curentFloor->on();
		} else if (i == 3) {
			curentFloor = &floor3;
			//curentFloor->off();
			uint8_t argArr[2] = { cntr1, cntr2 };
			curentFloor->push(argArr);
			curentFloor->on();
		} else if (i == 4) {
			curentFloor = &floor4;
			//curentFloor->off();
			//uint8_t argArr[2] = { cntr2, cntr1 };
			uint8_t argArr[2] = { cntr1, cntr2 };
			curentFloor->push(argArr);
			curentFloor->on();
			//i = 0;
		}

		curentFloor->delay(150000 *2);
		curentFloor->off();
		//curentFloor->delay(150000 / 3);

		cntr1++;
		cntr2--;

//		curentFloor->off();
//		uint8_t argArr[2] = {0xF0,0x00};
//		curentFloor->push(argArr);
//		curentFloor->on();
//
//		curentFloor->delay(150000 / div);
//
//		curentFloor->off();
////		curentFloor->push((uint8_t)0x5A + i);
//		curentFloor->on();
//
//		curentFloor->delay(150000 / div);
//
//		curentFloor->off();

		//i++;

	}
}

extern "C" void SysTick_Handler(void) {
	// Application SysTick
	static int counter = 0;
	counter++;
	if (counter == 50) {
		//SET_BIT(PORT1->OUT, 0);
		//CLR_BIT(PORT1->OUT, 1);
	}
	if (counter > 100) {
		//CLR_BIT(PORT1->OUT, 0);
		//SET_BIT(PORT1->OUT, 1);
		counter = 0;
	}
}
