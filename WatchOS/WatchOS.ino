#include "Sleep.h"
//make the serial buffer smaller(uses less ram)
#define SERIAL_BUFFER_SIZE 10
//Include spi for display
#include <SPI.h>
//include i2c for display
#include <Wire.h>
//Include gfx for the display
#include <Adafruit_GFX.h>
//include actuall display module
#include <Adafruit_SSD1306.h>
//sets the reset to pin 4 - no idea why though
#define OLED_RESET 4
//including clock
#include "Clock.h"
#include "In.h"
//#define i2c
#define spi

#ifdef spi
#define OLED_MOSI  11 //D1
#define OLED_CLK   13 //D0
#define OLED_DC    9
#define OLED_CS    10
#define OLED_RESET 8
//#define OLED_MOSI  D7
//#define OLED_CLK   D5
//#define OLED_DC    D4
//#define OLED_CS    D8
//#define OLED_RESET D3
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
#endif

#ifdef i2c
Adafruit_SSD1306 display(OLED_RESET);
#endif
extern bool currentState;
//externs the print3 function for usage(allows things like 001 and 021 to be printed
extern void print3(byte anum);
//externs the clock module for usage
extern Clock clock;
//wether or not display should be cleared(for paint)
bool clr = true;
bool sleep = false;
//function to do before sleep
void function() {
  //if clr is true-which is everywhere except paint-clr the display so nothing will be shown during sleep
  if (clr == true) {
    display.display();
    display.clearDisplay();
  }
  sleep = true;
}
//Includes events class
#include "Events.h"
//instance of events class which handles events
Events eventer;
Sleep sleeper(function, 30);
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
#include "In.h"
  //defines all outputs
#include "Out.h"
  digitalWrite(12, LOW);
  digitalWrite(12, HIGH);

  display.begin(SSD1306_SWITCHCAPVCC
#ifdef i2c
                , 0x3C
#endif
               );  // initialize with the I2C addr 0x3C (for the 128x64)
  // init done
  display.setTextSize(2); //set text size to 2
  display.setTextColor(WHITE); //set the text color to the regular white
  display.clearDisplay(); //clear the display of the adafruit buffer
  display.dim(true); //dim the display to save power
  //Serial.begin(9600); //begin serial connection for debugging
}

//loop code
void loop() {
  //change the text size to 1
  display.setTextSize(1);
  //sets the cursor to 0,0 (otherwise text will move)
  display.setCursor(0, 0);
  //check the events
  eventer.checkEvents();
  sleeper.loopCode(clock.tm.Minute, clock.tm.Second);
  //Choose whether to display the game or the clock
  if (currentState == 1) {
    clock.displayAll();
  }
  else {
    Game::cg->displayAll();
  }
  //-----------------------------------------------
  display.display(); // display the data in adafruit ssd1306's buffer

  //Check if clr is true (will not be if in paint) and do accordingly
  if (clr == true) {
    display.clearDisplay();
  }
}
