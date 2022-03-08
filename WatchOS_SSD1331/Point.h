#pragma once
#include "Arduino.h"
#include <SSD_13XX.h>
extern SSD_13XX display;
//point class (point on screen)
struct Point {
	byte x;
	byte y;
	void draw(uint16_t color = WHITE);
};

