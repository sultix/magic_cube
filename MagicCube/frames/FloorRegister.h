/*
 * FloorRegister.h
 *
 *  Created on: Dec 31, 2016
 *      Author: alex
 */

#ifndef FRAMES_FLOORREGISTER_H_
#define FRAMES_FLOORREGISTER_H_

#include <stdint.h>
#include <vector>

class FloorRegister {
public:
	FloorRegister();
	virtual ~FloorRegister();

	void addValue(uint8_t value);
	uint8_t getValue(int index);
	unsigned int count(void);

private:
	std::vector<uint8_t> values_;

};

#endif /* FRAMES_FLOORREGISTER_H_ */
