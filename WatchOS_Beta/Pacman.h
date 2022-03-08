/*
 * Pacman.h
 *
 * Created: 4/30/2017 4:11:53 PM
 *  Author: A cool dude
 */ 


#ifndef PACMAN_H_
#define PACMAN_H_
#include "Game.h"
#include "Rect.h"
#include "Line.h"
//pacman the musical
class Pacman : public Game {
	//the pacman character
	Rect pacman{57, 50, 13,13};
  //the ghosts
	Rect ghosts[4] = {Rect{57,10,12,12}, Rect{43,32,12,12}, Rect{58,32,12,12}, Rect{73,32,12,12}};
	//the direction pacman is going (255 means nowhere)
	byte direction = 255;
  //whether or not pacman is eating right now
	bool eat = true;
  //lives left
	byte lives = 3;
  //current score
	byte score = 0; 
public:
	Pacman();
	void Up();
	void Down();
	void Left();
	void Right();
	void Special();
	void Specialholdoff();
	void displayAll();

};



#endif /* PACMAN_H_ */

