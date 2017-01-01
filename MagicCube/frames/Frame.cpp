/*
 * Frame.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: alex
 */

#include <frames/Frame.h>

Frame::Frame() {

}

Frame::~Frame() {
}

void Frame::setDuration(unsigned int duration){
	duration_ = duration;
}

unsigned int Frame::getDuration(){
	return duration_;
}

int Frame::getFloorsCount(void){
	return values_.size();
}

void Frame::init(uint8_t* data, int length){
	for(int i = 0; i < length; i++){
		addValue(data[i]);
	}
}

void Frame::addValue(uint8_t value){
	values_.push_back(value);
}

uint8_t Frame::getValue(int index){
	return values_[index];
}

unsigned int Frame::count(void){
	return values_.size();
}
