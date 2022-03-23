/*
 * Rect.h
 *
 * Created: 4/30/2017 4:30:09 PM
 *  Author: A cool dude
 */ 

#pragma once
#ifndef RECT_H_
#define RECT_H_

#include "Point.h"
#include "Line.h"
#include "Arduino.h"
#include "Circle.h"
#include "Color.h"

//rectangle
struct Line;
struct Rect {
	byte x;
	byte y;
	byte w;
	byte h;
  //checks intersection
	bool intersects(Line aline);
	bool intersects(Rect arect);
	bool intersects(Circle acircle);
	bool includes(Point apoint);
  
	void draw(uint16_t color = WHITE);
};



#endif /* RECT_H_ */
