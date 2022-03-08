/*
#include "Paint.h"

extern bool lastRight;
extern bool lastLeft;
extern bool lastUp;
extern bool lastDown;
extern bool lastSpecial;
Paint::Paint() {
  display.clearScreen();
}
#define delayTime 150
void Paint::Up() {
  if (y != 0) {
    y -= increment;
  }
  else {
    y = 64 - increment;
  }
  delay(delayTime);
}
void Paint::Down() {

  if (y != 64 - increment) {
    y += increment;
  }
  else {
    y = 0;
  }
  delay(delayTime);
}
void Paint::Left() {

  if (x != 0) {
    x -= increment;
  } else {
    x = display.width() - increment;
  }
  delay(delayTime);
}
void Paint::Right() {

  if (x != display.width() - increment) {
    x += increment;
  }
  else {
    x = 0;
  }
  delay(delayTime);
}
void Paint::Special() {
  hold++;
  if (hold == 50) {
    hold = 0;
    increment *= 2;
    x = 0;
    y = 0;
    if (increment > 16) {
      lincrement = increment;
      increment = 1;
    }
  }
  //  display.fillRect(x, y, increment, increment, INVERSE);
  //
  if (lastSpecial == false && lincrement == increment) {
    display.fillRect(x, y, increment, increment, WHITE);

  }
  else {
    if (lincrement != increment) {
      lincrement = increment;
    }
  }
}
void Paint::displayAll() {
  if (iffy == false) {
    display.clearScreen();
    iffy = true;
  }
  if (lx == x && ly == y) {

  }
  else {
    if (c == true)
      display.fillRect(lx , ly, increment,  increment, BLACK);
    c = false;
  }
  display.fillRect(x, y, increment,  increment, BLACK);

  c = !c;
  lx = x;
  ly = y;
  if(lastSpecial == false) {
    hold = 0;
  }
}
//Do a incrementxincrement sqaure
*/

