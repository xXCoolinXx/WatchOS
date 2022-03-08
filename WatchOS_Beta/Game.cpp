#include "Game.h"
#include "Paint.h"
#include "Pong.h"
#include "Pacman.h"
#include "Galaga.h"
#include "Maze.h"
extern bool lastLeft;
extern bool lastRight;
Game::Game() {

}


//Game* Game::cg = NULL;
byte Game::gameSelect = 0;

/*
void Game::changeGame(bool updown) {
	
}
*/
void Game::Left() {
}

void Game::Right() {

}
void Game::Up() {
}
void Game::Down() {
}
void Game::Special() {
}
void Game::select() {
  //delete cg;

  if (gameSelect == 0) {
    //cg = new Paint();
  }
  else if(gameSelect == 1) {
    //cg = new Pong();
  }
  else if(gameSelect == 2) {
    //cg = new Pacman();
  }
  else if(gameSelect == 3) {
    //cg = new Galaga();
  }
  else if(gameSelect == 4) {
    //cg = new Maze();
  }
  gameSelect = 0;
}
void Game::displayAll() {
  
}
void Game::Specialholdoff() {

}



