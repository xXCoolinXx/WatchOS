#pragma once
#include "Game.h"
#include "Rect.h"
#include "Line.h"
#define Count 10
#define NUM_ALIEN_COLUMNS 7
#define NUM_ALIEN_ROWS 3
#define X_START_OFFSET 6
#define SPACE_BETWEEN_ALIEN_COLUMNS 5
#define LARGEST_ALIEN_WIDTH 11
#define SPACE_BETWEEN_ROWS 9
//classic (tm) space invaders game
class SpaceInvaders : public Game {
    //the player's ship
    Rect Destroyer{0, 64-7, 11, 7};
    //private class that allows some of the ammo to not be in use
    struct Ammo : public Line {
      bool init = false;
    };
    struct AlienRect : public Rect{
      bool alive = true;
    };
    
    //The array of aliens across the screen
    AlienRect Alien[NUM_ALIEN_COLUMNS/*Columns*/][NUM_ALIEN_ROWS/*Rows*/];
    //all ammo currently existing
    Ammo shots[Count];
    Ammo enemyShots[5];
    short score = 0;
  public:
    SpaceInvaders();
    void Up();
    void Down();
    void Left();
    void Right();
    void Special();
    void displayAll();
    void moveAliens();
    void enemyFire();
};



