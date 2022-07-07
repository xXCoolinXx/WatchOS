#pragma once
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <TimeLib.h>

#define CHAR_WIDTH 5
#define CHAR_SPACE_W 6
#define CHAR_HEIGHT 7

void print2(short number, Adafruit_SSD1331* display);

void print2_space(short number, Adafruit_SSD1331* display);

void print_time(tmElements_t tm, Adafruit_SSD1331* display);

void clear_chars(short x, short y, short num_chars, Adafruit_SSD1331* display);
