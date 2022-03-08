#include "SleepInterval.h"

#include <SPI.h>
#include <SSD_13XX.h>


#define __CS1  10
#define __DC   8


SSD_13XX display = SSD_13XX(__CS1, __DC);

#include "Clock.h"
#include "In.h"

extern bool currentState;
//externs the print3 function for usage(allows things like 001 and 021 to be printed
extern void print3(byte anum);
//externs the clock module for usage
extern Clock clock;
bool sleep = false;
//function to do before sleep
void function() {
  display.changeMode(ALL_OFF);
  sleep = true;
}
//Includes events class
#include "Events.h"
//instance of events class which handles events
Events eventer;
SleepInterval sleeper(function, 30);
//sets up everything

void setup() {
  
  pinMode(LEFT, INPUT_PULLUP);

  pinMode(UP, INPUT_PULLUP);

  pinMode(DOWN, INPUT_PULLUP);

  pinMode(SPECIAL, INPUT_PULLUP);

  pinMode(TOGGLE, INPUT_PULLUP);

  pinMode(RIGHT, INPUT_PULLUP);
  randomSeed(analogRead(0));
  // put your setup code here, to run once:
  //defines all inputs
  //defines all outputs
  pinMode(12, OUTPUT);
  
  display.begin( );
  digitalWrite(12, HIGH);

  // init done
}

//loop code
void loop() {
  //change the text size to 1
  display.setTextScale(1);
  //sets the cursor to 0,0 (otherwise text will move)
  display.setCursor(0, 0);
  //check the events

  eventer.checkEvents();
  clock.checkAll();
  sleeper.loopCode(clock.tm.Minute, clock.tm.Second);

  //Choose whether to display the game or the clock
  if (sleeper.disableSleepCycle) {
    if (currentState == 1) {
      clock.displayAll();
    }
    else {
      Game::cg->displayAll();
    }
  }
}

