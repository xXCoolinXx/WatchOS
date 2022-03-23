//#include "Sleep.h"
//make the serial buffer smaller(uses less ram)
#define SERIAL_BUFFER_SIZE 10
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>

// You can use any (4 or) 5 pins 
//#define sclk 13
//#define mosi 11
//#define cs   10
//#define rst  9
//#define dc   8

#define sclk 14
#define mosi 13
#define cs   4
#define rst  15
#define dc   5

Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, mosi, sclk, rst);  
#include "Clock.h"
#include "In.h"

extern bool currentState;
//externs the print3 function for usage(allows things like 001 and 021 to be printed
extern void print3(byte anum);
//externs the clockzmodule for usage
extern Clock clockz;
//wether or not display should be cleared(for paint)
bool clr = true;
bool sleep = false;
//function to do before sleep
void function() {
  //if clr is true-which is everywhere except paint-clr the display so nothing will be shown during sleep
  if (clr == true) {
    display.fillScreen(BLACK);
  }
  sleep = true;
}
//Includes events class
#include "Events.h"
//instance of events class which handles events
Events eventer;
//Sleep sleeper(function, 30);
//sets up everything
void setup() {
  //pinMode(LEFT, INPUT_PULLUP);

  //pinMode(UP, INPUT_PULLUP);

  //pinMode(DOWN, INPUT_PULLUP);

  //pinMode(SPECIAL, INPUT_PULLUP);

  //pinMode(TOGGLE, INPUT_PULLUP);

  //pinMode(RIGHT, INPUT_PULLUP);
  //randomSeed(analogRead(0));
  // put your setup code here, to run once:
  //defines all inputs
#include "In.h"
  //defines all outputs
#include "Out.h"
  digitalWrite(12, LOW);
  digitalWrite(12, HIGH);

  display.begin();  // initialize with the I2C addr 0x3C (for the 128x64)
  // init done
  display.setTextSize(2); //set text size to 2
  display.setTextColor(WHITE); //set the text color to the regular white
  display.fillScreen(BLACK); //clear the display of the adafruit buffer
  
  Serial.begin(115200); //begin serial connection for debugging
}

//loop code
void loop() {
  //change the text size to 1
  display.setTextSize(1);
  //sets the cursor to 0,0 (otherwise text will move)
  display.setCursor(0, 0);
  //check the events
  eventer.checkEvents();
  //sleeper.loopCode(clockztm.Minute, clockztm.Second);
  //Choose whether to display the game or the clock
  
  if (currentState == 1) {
    clockz.displayAll();
  }
  else {
    Game::cg->displayAll();
  }
  //-----------------------------------------------

  //Check if clr is true (will not be if in paint) and do accordingly
  if (clr == true) {

    //display.fillScreen(BLACK);
  }
  
}
