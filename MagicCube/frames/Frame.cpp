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

void Frame::addFloorData(FloorRegister* data){
	floorData_.push_back(data);
}

void Frame::setDuration(unsigned int duration){
	duration_ = duration;
}

FloorRegister* Frame::getFloorData(unsigned int floorIndex){
	if(floorIndex < 0 || floorIndex >= floorData_.size()){
		return NULL;
	}

	return floorData_[floorIndex];
}

unsigned int Frame::getDuration(){
	return duration_;
}

unsigned int Frame::getFloorsCount(void){
	return floorData_.size();
}

void Frame::init(std::string data){
	std::vector<char*> floors = split(data, ';');

	for(unsigned int i = 0; i < floors.size(); i++){

		std::string sfloor = floors[i];
		std::vector<char*> regs = split(sfloor, ',');

		for(unsigned int j = 0; j < regs.size(); j++){
			 char* temp = (char*)malloc(sizeof(char) * strlen(regs[i]));
			 strcpy (temp,regs[i]);
			 long value = strtol(temp, &temp, CONV_TO_HEX);
			 free(temp);
			 FloorRegister* freg = new FloorRegister();
			 freg->addValue(value);
			 addFloorData(freg);
		}
	}
}

char* Frame::strsep(char **stringp, const char *delim) {
  if (*stringp == NULL) { return NULL; }
  char *token_start = *stringp;
  *stringp = strpbrk(token_start, delim);
  if (*stringp) {
    **stringp = '\0';
    (*stringp)++;
  }
  return token_start;
}

std::vector<char*> Frame::split(const std::string &s, char delim) {
    std::vector<char*> elems;

    char *str = strdup(s.c_str());  // We own str's memory now.
    char *token;
    while ((token = strsep(&str, ","))) elems.push_back(token);
    free(str);

    return elems;
}
