#pragma once
//get the display for drawing
#include <SPI.h>
#include <SSD_13XX.h>
extern SSD_13XX display;
//predefinition of class Events
//basic framework for displaying and using the buttons
class App {
	public:
	App();
	virtual void Up()=0;
	virtual void Down()=0;
	virtual void Left()=0;
	virtual void Right()=0;
	virtual void Special()=0;
	virtual void displayAll()=0;
};



