#include "Clock.h"
extern Clock clock;
extern bool isSleep;
bool lastSpecial = false;
bool lastUp = false;
bool lastDown = false;
bool lastLeft = false;
bool lastRight = false;
bool currentState = true;
bool lastToggle = false;
#include "In.h"

void Events::Left() {
  if (!digitalRead(LEFT)) {
    if (currentState) {
      clock.Left();
    }
    else {
      Game::cg->Left();
    }
    lastLeft = true;
  }
  else {
    lastLeft = false;
  }
}

void Events::Right() {
  if (!digitalRead(RIGHT)) {
    if (currentState) {
      clock.Right();
    }
    else {
      Game::cg->Right();
    }
    lastRight = true;
  }
  else {
    lastRight = false;
  }
}

void Events::Up() {
  if (!digitalRead(UP)) {
    if (currentState) {
      clock.Up();
    }
    else {
      Game::cg->Up();
    }
    lastUp = true;
  }
  else {
    lastUp = false;
  }
}

void Events::Down() {
  if (!digitalRead(DOWN)) {
    if (currentState) {
      clock.Down();
    }
    else {
      Game::cg->Down();
    }
    lastDown = true;
  }
  else {
    lastDown = false;
  }
}

void Events::toZed() {
}

void Events::checkSpecial() {
  bool out3 = !digitalRead(SPECIAL);
  if (out3 == HIGH) {

    toZed();
    if (currentState == HIGH ) {
      clock.Special();
    }
    else {
      //      specialhold = LOW;
      //Replace with something special - ha ha ha

      Game::cg->Special();
    }
    lastSpecial = true;
  }
  else {
    clock.Specialholdoff();
    Game::cg->Specialholdoff();
    lastSpecial = false;
  }
}

void Events::checkToggle() {
  bool out9 = !digitalRead(TOGGLE);
  if (out9 == HIGH) {
    if (currentState == 1) {
      clock.Toggle();
    }
    if (currentState == 0) {
      display.clearDisplay();
      display.setCursor(0, 0);
      display.setTextSize(2);
      display.println(F("Closing..."));
      display.display();
      digitalWrite(9, LOW);
    }
    lastToggle = true;
  }
  else {
    lastToggle = false;
  }
}

void Events::checkEvents() {

  checkToggle();

  //get RTC time and set to rtc_time
  clock.Read();

  checkSpecial();
  Up();
  Down();
  Left();
  Right();

  clock.Write();
}

Events::Events() {
}
