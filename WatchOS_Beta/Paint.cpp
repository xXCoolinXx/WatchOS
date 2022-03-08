#include "Paint.h"

extern byte buffer[];
extern bool clr;

extern bool lastRight;
extern bool lastLeft;
extern bool lastUp;
extern bool lastDown;
extern bool lastSpecial;
Paint::Paint() {
  display.clearDisplay();

  clr = false;
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
  if (hold == 10) {
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
  //  delay(100);
}
void Paint::displayAll() {
  if (iffy == false) {
    display.clearDisplay();
    iffy = true;
  }
  if (lx == x && ly == y) {

  }
  else {
    if (c == true)
      display.fillRect(lx , ly, increment,  increment, INVERSE);
    c = false;
  }
  display.fillRect(x, y, increment,  increment, INVERSE);
  
  c = !c;
  lx = x;
  ly = y;
}
void Paint::Specialholdoff() {
  if (lastSpecial == true && lincrement == increment) {
    display.fillRect(x, y, increment, increment, INVERSE);
    //delay(100);
  }
  else {
    if (lincrement != increment) {
      lincrement = increment;
    }
  }
  hold = 0;
}
//Do a incrementxincrement sqaure

