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
#include <string>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "FloorRegister.h"

class Frame {
public:
	Frame();
	virtual ~Frame();

	void addFloorData(FloorRegister* data);
	void setDuration(unsigned int duration);

	void init(std::string data);

	FloorRegister* getFloorData(unsigned int floorIndex);
	unsigned int getDuration(void);
	unsigned int getFloorsCount(void);

private:
	std::vector<FloorRegister*> floorData_;
	unsigned int duration_;

	char* strsep(char **stringp, const char *delim);
	std::vector<char*> split(const std::string &s, char delim);
};

#endif /* FRAMES_FRAME_H_ */
