#include "Game.h"
#include "Paint.h"
#include "Pong.h"
//#include "Pacman.h"
#include "SpaceInvaders.h"
#include "Maze.h"
#include "Flashlight.h"
#include "Calculator.h"

Game::Game() {}

Game* Game::cg = NULL;
byte Game::gameSelect = 0;

void Game::Left() {}
void Game::Right() {}
void Game::Up() {}
void Game::Down() {}
void Game::Special() {}

void Game::select() {
 delete cg;

  if (gameSelect == 0) {
    
    cg = new Flashlight();
  }
  else if(gameSelect == 1) {
    cg = new Pong();
  }
  else if(gameSelect == 2) {
    cg = new Maze();
    
  }
  else if(gameSelect == 3) {
   cg = new SpaceInvaders();
  }
  else if(gameSelect == 4) {
    cg = new Calculator();
  }
  else if(gameSelect == 5) {
    //cg = new Paint();
  }
  gameSelect = 0;
}
void Game::displayAll() {}




