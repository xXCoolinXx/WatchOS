#pragma once
#include "Circle.h"
#include "Rect.h"
#include "Point.h"
struct Rect;
//creates a line with an easy to use drawing method
struct Line {
	Point a;
	Point b;
	void draw(uint16_t color = WHITE);
  bool intersects(Circle acircle);
  bool intersects(Rect arect);
  bool intersects(Line line);
};

