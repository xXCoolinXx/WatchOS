#pragma once
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Game.h"
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
//Allows for the direction be chosen
enum Direction {
	left, right, up, down
};
//allows for easier use of buttons
class Events {
	//Check buttons 
  void Left();
  void Right();
	void Up();
  void Down();
	void checkSpecial();
	void checkToggle();

	//Utility functions; Don't actually check buttons
	//sets sleep to zero when button is pressed so that it doesn't sleep during activity
	void toZed();

	public:
	Events();
  //current state (ie clock = 1 and games = 0)
	//Ties all the private functions together
	void checkEvents();
};


