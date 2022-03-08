/*
 * Draw.cpp
  Defines draw functions for all of the derived classes (their only functions except for rect)
 */ 
 #include "Point.h"
 #include "Line.h"
 #include "Rect.h"
 void Point::draw()
 {
	display.drawPixel(x,y, WHITE);
 }
 void Line::draw() {
	display.drawLine(a.x,a.y, b.x, b.y, WHITE);
 }
 void Rect::draw(uint16_t color) {
	display.fillRect(x,y,w,h,color);
 }

