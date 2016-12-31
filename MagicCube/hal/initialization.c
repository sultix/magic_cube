/*
 * initialization.c
 *
 *  Created on: Dec 30, 2016
 *      Author: alex
 */

#include "hal/initialization.h"

void initApplication() {
	// SystemTimer auf 10ms konfigurieren
	SysTick_Config(SystemCoreClock / 100);

	// Konfiguriere Pin1.0 als Ausgang
	PORT1->IOCR0 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 0 * 8);		//RED LED PIN 1.0
	PORT1->IOCR0 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 1 * 8);		//RED LED PIN 1.1

	PORT2->IOCR4 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 3 * 8); 		//1 Floor PIN 2.7
	PORT2->IOCR8 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 1 * 8); 		//2 Floor PIN 2.9
	PORT2->IOCR8 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 2 * 8); 		//3 Floor PIN 2.10
	PORT2->IOCR8 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 3 * 8); 		//4 Floor PIN 2.11

	PORT0->IOCR0 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 0 * 8);		//DATA1 PIN 0.0
	PORT0->IOCR4 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 1 * 8);		//DATA2 PIN 0.5

	PORT0->IOCR4 |= (XMC_GPIO_MODE_OUTPUT_PUSH_PULL << 2 * 8);		//CLK PIN 0.6

	// Konfiguriere Pin1.15 als Eingang ohne PullUp
	//PORT1->IOCR12 |= (XMC_GPIO_MODE_INPUT_TRISTATE <<3*8);

}
