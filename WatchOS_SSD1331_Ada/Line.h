/*
 * Line.h
 *
 * Created: 5/2/2017 4:38:20 PM
 *  Author: A cool dude
 */ 
#pragma once

#ifndef LINE_H_
#define LINE_H_
#include "Arduino.h"
#include "Circle.h"
#include "Rect.h"
#include "Point.h"
struct Rect;
//creates a line with an easy to use drawing method
struct Line {
	Point a;
	Point b;
	void draw();
  bool intersects(Circle acircle);
  bool intersects(Rect arect);
};

#endif /* LINE_H_ */
