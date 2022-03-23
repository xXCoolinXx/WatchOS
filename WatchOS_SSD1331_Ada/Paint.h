#pragma once
#include "Game.h"

class Paint : public Game {

	//current x of cursor
	byte x = 0;
  //current y of cursor
	byte y = 0;
  //allows flicker on currentplace so users know where it is
	bool c = false;
  //the last x(to make sure it is its old self)
	byte lx = 0;
  //the last y(to make sure it is its old self
	byte ly = 0;
  //size
	byte increment = 1;
  //last increment
	byte lincrement = increment;
  //hold so that increment can be changed
	byte hold;
  //this ones a bit iffy...
  bool iffy = 0;
	public:
	Paint();
	void Up();
	void Down();
	void Left();
	void Right();
	void Special();
	void displayAll();
	void Specialholdoff();
};
