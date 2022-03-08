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
	//ai's y
	//byte ai_y = 0;
	//player's y
	//byte player_y = 0;
  //player's score
	//byte player = 0;
  //ai's score
	//byte ai = 0;
  //ball's x and y
	//byte ball_x = 63;
	//byte ball_y = 31;
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
  //checks collision (will be removed once switched to rect
	void checkCollision(bool rect);
};

