#include "Clock.h"
#include "SleepInterval.h"
extern SleepInterval sleeper;
extern Clock clock;
extern bool sleep;
bool lastSpecial = false;
bool lastUp = false;
bool lastDown = false;
bool lastLeft = false;
bool lastRight = false;
bool currentState = true;
bool lastToggle = false;
#include "In.h"

void Events::Left() {
  if (!digitalRead(LEFT) || analogRead(1) < 250) {
    if (currentState) {
      clock.Left();
    }
    else {
      Game::cg->Left();
    }
    lastLeft = true;
    sleeper.resetSleep();
  }
  else {
    lastLeft = false;
  }
}

void Events::Right() {
  if (!digitalRead(RIGHT) || analogRead(1) > 750) {
    if (currentState) {
      clock.Right();
    }
    else {
      Game::cg->Right();
    }
    lastRight = true;
    sleeper.resetSleep();
  }
  else {
    lastRight = false;
  }
}

void Events::Up() {
  if (!digitalRead(UP) || analogRead(0) > 750) {
    if (currentState) {
      clock.Up();
    }
    else {
      Game::cg->Up();
    }
    lastUp = true;
    sleeper.resetSleep();
  }
  else {
    lastUp = false;
  }
}

void Events::Down() {
  if (!digitalRead(DOWN) || analogRead(0) < 250) {
    if (currentState) {
      clock.Down();
    }
    else {
      Game::cg->Down();
    }
    lastDown = true;
    sleeper.resetSleep();
  }
  else {
    lastDown = false;
  }
}


void Events::checkSpecial() {
  bool out3 = !digitalRead(SPECIAL);
  if (out3 == HIGH) {

    if (currentState == HIGH ) {
      clock.Special();
    }
    else {
      //      specialhold = LOW;
      //Replace with something special - ha ha ha

      Game::cg->Special();
    }
    sleeper.resetSleep();
    lastSpecial = true;
  }
  else {
    lastSpecial = false;
  }
}


void softReset() // Restarts program from beginning but does not reset the peripherals and registers
{
  asm volatile ("  jmp 0");
}

void Events::checkToggle() {
  bool out9 = !digitalRead(TOGGLE);
  if (out9 == HIGH && !sleep) {
    if (currentState == 1) {
      clock.Toggle();
    }
    if (currentState == 0) {
      softReset();
      //digitalWrite(12, LOW);
    }

    sleeper.resetSleep();
    lastToggle = true;
  }
  else if (sleep) {
    if (sleeper.disableSleepCycle) {
      sleep = false;
      display.changeMode(NORMAL);
      delay(500);
    }
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

