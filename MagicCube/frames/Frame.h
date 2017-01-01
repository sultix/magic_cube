/*
 * Frame.h
 *
 *  Created on: Dec 30, 2016
 *      Author: alex
 */

#ifndef FRAMES_FRAME_H_
#define FRAMES_FRAME_H_

#define CONV_TO_HEX 16

#include <cstddef>
#include <vector>
#include <inttypes.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#include "declarations.h"
#include "FloorRegister.h"

class Frame {
public:
	Frame();
	virtual ~Frame();

	void setDuration(unsigned int duration);

	void init(uint8_t* data, int length);

	unsigned int getDuration(void);
	int getFloorsCount(void);

	void addValue(uint8_t value);
	uint8_t getValue(int index);
	unsigned int count(void);

private:
	std::vector<FloorRegister*> floorData_;
	unsigned int duration_;

	std::vector<uint8_t> values_;
};

#endif /* FRAMES_FRAME_H_ */
