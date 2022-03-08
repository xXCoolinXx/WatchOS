#pragma once
#include "App.h"
//class Paint;
class Pong;
//class Pacman;
class SpaceInvaders;
class Maze;
class Calculator;
//Framework for games
class Game : public App {
  protected:
    bool pause = false;
    //friend class Events;
    //allows clock to select the current game
    friend class Clock;
    //total amount (cannot be dynamic because of RAM)
    const static PROGMEM byte totalGames = 6;
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
    //select the game from gameSelect and put it in cg
    static void select();
};


