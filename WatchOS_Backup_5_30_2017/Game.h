#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#pragma once

//#include "Runner.h"
#include "App.h"
class Paint;
class Pong;
class Pacman;
class Galaga;
//Framework for games
class Game : public App {
  //friend class Events;
  //allows clock to select the current game
  friend class Clock;
	//total amount (cannot be dynamic because of RAM)
	const static PROGMEM byte totalGames = 5;
  //current gameSelection
	static byte gameSelect;
	//static void changeGame(bool updown);
public:
  //current game
	static Game* cg;
	
	Game();
	virtual void Up();
	virtual void Down();
	virtual void Left();
	virtual void Right();
	virtual void Special();
	virtual void displayAll();
	virtual void Specialholdoff();
  //select the game from gameSelect and put it in cg
  static void select();
};

