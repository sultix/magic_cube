/*
 * XObject.cpp
 *
 *  Created on: Dec 30, 2016
 *      Author: alex
 */

#include <XObject.h>

XObject::XObject() {

}

XObject::~XObject() {
}

void XObject::delay(unsigned len)
{
	while(len--);
}

