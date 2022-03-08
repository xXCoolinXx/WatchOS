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

//allows for easier use of buttons
class Events {
	//Check buttons 
  void Left();
  void Right();
	void Up();
  void Down();
	void checkSpecial();
	void checkToggle();

	public:
	Events();
  //current state (ie clock = 1 and games = 0)
	//Ties all the private functions together
	void checkEvents();
};



