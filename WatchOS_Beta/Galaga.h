#pragma once
#include "Game.h"
#include "Rect.h"
#include "Line.h"
//classic (tm) galaga game
class Galaga : public Game {
  //the player's ship
  Rect ship{0,38,19,15};
  //private class that allows some of the ammo to not be in use
  struct Ammo : public Line {
    //whether or not it should be drawn or checked for collision with something
    bool init;
  };
  //amount it can fire (limited due to RAM)
  #define Count 1
  //all ammo currently existing
  Ammo shots[Count];
  public:
  Galaga();
  void Up();
  void Down();
  void Left();
  void Right();
  void Special();
  void Specialholdoff();
  void displayAll();
};


