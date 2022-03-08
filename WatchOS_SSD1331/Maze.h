#include "Game.h"
#include "Rect.h"
#define MAX_WALLS 20
#define END 1

class Maze : public Game {
  Circle ball;
  //The maximum is MAX_WALLS, but it will vary for every map
  Line walls[MAX_WALLS+END];
  //The amount can be change through this variable
  byte amountOfWalls = 0;
  //and the current map can be changed through here
  byte currentMap;
  public:
  void Left();
  void Right();
  void Up();
  void Down();
  void Special();
  void displayAll();
  Maze();
};



