/*
 * declarations.h
 *
 *  Created on: Dec 30, 2016
 *      Author: alex
 */

#ifndef DECLARATIONS_H_
#define DECLARATIONS_H_


#define PIN_1_FLOOR 10 	//P2.10
#define PIN_2_FLOOR 11 	//P2.11
#define PIN_3_FLOOR 6 	//P0.6
#define PIN_4_FLOOR 7 	//P0.7

#define PIN_DATA_1 	0 	//P0.0
#define PIN_DATA_2 	5 	//P0.5

#define PIN_CLK		9 	//P0.9

#define PIN_VCC		14 	//P0.14


#define DELAY_TIME 0


struct __AccessPoint{

	volatile uint32_t* port;
	uint32_t pin;

} typedef AccessPoint;

#endif /* DECLARATIONS_H_ */
