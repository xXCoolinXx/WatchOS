#include "Flashlight.h"
extern bool lastSpecial;
extern bool clr;

void Flashlight::Up() {};
void Flashlight::Down() {};
void Flashlight::Left() {};
void Flashlight::Right() {};
void Flashlight::Special() {
  if (lastSpecial == false) {
    displayDim = !displayDim;
    display.dim(displayDim);
    digitalWrite(12, !displayDim);
  }
};
Flashlight::Flashlight() {
  digitalWrite(12, !displayDim);
};
void Flashlight::displayAll() {
};

