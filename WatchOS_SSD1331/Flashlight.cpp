#include "Flashlight.h"
extern bool lastSpecial;
#include "SleepInterval.h"
extern SleepInterval sleeper;


void Flashlight::Up() {};
void Flashlight::Down() {};
void Flashlight::Left() {};
void Flashlight::Right() {};
void Flashlight::Special() {};
Flashlight::Flashlight() {
  display.clearScreen();
  display.fillScreen (WHITE);
  delay(100);
  display.clearScreen();
};
void Flashlight::displayAll() {
  display.fillScreen (WHITE);
  sleeper.resetSleep();
};


