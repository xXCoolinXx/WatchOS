#pragma once
#include "Game.h"

class Flashlight : public Game {
  public:
  void Up();
  void Down();
  void Left();
  void Right();
  void Special();
  void displayAll();
  Flashlight();
  bool displayDim = false;
};
