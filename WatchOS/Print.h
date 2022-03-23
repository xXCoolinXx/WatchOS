#pragma once
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <TimeLib.h>

void print2(short number, Adafruit_SSD1331* display);

void print2_space(short number, Adafruit_SSD1331* display);

void print_time(tmElements_t tm, Adafruit_SSD1331* display);
