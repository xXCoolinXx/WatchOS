#include "Game.h"
#include "Point.h"
#include "Rect.h"


class Calculator : public Game {
  byte d = 0;
  char calculatorChar[20];
  Point Cursor{0,43};
  Rect buttons[4][5];
  public:
    void Up();
    void Down();
    void Left();
    void Right();
    void Special();
    void displayAll();
    Calculator();
};


