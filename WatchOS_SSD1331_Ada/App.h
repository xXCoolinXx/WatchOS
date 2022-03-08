#pragma once
#include "Color.h"
//get the display for drawing
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>

extern Adafruit_SSD1331 display;
//predefinition of class Events
class Events;
//basic framework for displaying and using the buttons
class App {
	public:
	App();
	virtual void Up()=0;
	virtual void Down()=0;
	virtual void Left()=0;
	virtual void Right()=0;
	virtual void Special()=0;
	virtual void Specialholdoff()=0;
	virtual void displayAll()=0;
};


