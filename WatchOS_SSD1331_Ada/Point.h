/*
 * PointRect.h
 *
 * Created: 4/30/2017 4:29:31 PM
 *  Author: A cool dude
 */ 
#pragma once
#include "Arduino.h"

#ifndef POINTRECT_H_
#define POINTRECT_H_
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
extern Adafruit_SSD1331 display;
//point class (point on screen)
struct Point {
	byte x;
	byte y;
	void draw();
};




#endif /* POINTRECT_H_ */
