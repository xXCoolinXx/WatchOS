#include "Maze.h"


/*
Template for maze maps (below)
const Line progmem map[] 
{
  
  
  ,1//End
};
*/



Maze::Maze()
{
  ball.x = 10;
  ball.y = 10;
  ball.r = 3;
}
#define DELAY_TIME 5
void Maze::Left() 
{
  ball.x--;
  delay(DELAY_TIME);
  //Feature for checking walls
}

void Maze::Right() 
{
  ball.x++;  
  delay(DELAY_TIME);
  //Feature for checking walls
}

void Maze::Up() 
{
  ball.y--;
  delay(DELAY_TIME);
  //Feature for checking walls  
}

void Maze::Down() 
{
  ball.y++;  
  delay(DELAY_TIME);
  //Feature for checking walls
}

void Maze::Special() 
{
  //Nothing here  
}

void Maze::displayAll() 
{
  display.fillCircle(ball.x,ball.y,ball.r,WHITE);
  display.clearScreen(); //Not permanent, just for testing  
  delay(5);
}


