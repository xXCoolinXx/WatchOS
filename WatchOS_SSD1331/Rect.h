#pragma once
#include "Point.h"
#include "Line.h"
#include "Arduino.h"
#include "Circle.h"
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

