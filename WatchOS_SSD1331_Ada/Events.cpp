#include "Clock.h"
#include "Sleep.h"
extern Sleep sleeper;
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
    clock.Specialholdoff();
    //Game::cg->Specialholdoff();
    lastSpecial = false;
  }
}


#include <avr/wdt.h>

void wdt_init(void) __attribute__((naked)) __attribute__((section(".init3")));
// Function Implementation
void wdt_init(void)
{
    MCUSR = 0;
    wdt_disable();

    return;
}

#define softRestart()        \
do                          \
{                           \
    wdt_enable(WDTO_15MS);  \
    for(;;)                 \
    {                       \
    }                       \
} while(0)


void Events::checkToggle() {
  bool out9 = !digitalRead(TOGGLE);
  if (out9 == HIGH && !sleep) {
    if (currentState == 1) {
      clock.Toggle();
    }
    if (currentState == 0) {
      display.fillScreen(BLACK);
      display.setCursor(0, 0);
      display.setTextSize(2);
      //softRestart();
      digitalWrite(12, LOW);
    }
    
    sleeper.resetSleep();
    lastToggle = true;
  }
  else if(sleep) {
    sleep = false;
    delay(500);
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
