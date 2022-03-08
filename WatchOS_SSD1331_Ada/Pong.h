#pragma once
#include "Game.h"
#include "Rect.h"
#include "Circle.h"
class Pong : public Game{
	struct User : public Rect {
    byte score;
	};
  Circle ball;
  
  User player;
  User ai;
  //is the ball going left or right?
	byte directionx;
	//is it going up, down, or neither?
	byte directiony = 1;
public:
	Pong();
	void Up();
	void Down();
	void Left();
	void Right();
	void Special();
	void Specialholdoff();
	void displayAll();
  //checks collision 
	void checkCollision(bool rect/*um*/);
  void Countdown();
};

