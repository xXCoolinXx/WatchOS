#include "Calculator.h"
//smaller windows like cursor
const unsigned char PROGMEM cursOR[]
{
  0xe0,
  0xc0,
  0xa0,
  0x10
};
#define val 1
void Calculator::Up()
{
  Cursor.y -= val;
  if (Cursor.y > 230) {
    Cursor.y = 0;
  }
}

void Calculator::Down()
{
  if (!(Cursor.y + val + 4 >= 63)) {
    Cursor.y += val;
  }
}

void Calculator::Left()
{
  Cursor.x -= val;
  if (Cursor.x > 230) {
    Cursor.x = 0;
    delay(100);
  }
}

void Calculator::Right()
{
  Cursor.x += val;
  if (Cursor.x + 4 > display.width()/*display.width()*/ - 1) {
    Cursor.x = display.width() - 5;
    delay(100);
  }
}

void Calculator::Special()
{

}

void Calculator::displayAll()
{
  if(d == 0) { display.clearScreen(); d = 1; }
  display.drawBitmap(Cursor.x, Cursor.y, cursOR, 4, 4, WHITE);
  delay(10);
  display.drawBitmap(Cursor.x, Cursor.y, cursOR, 4, 4, BLACK);
}

Calculator::Calculator()
{
  display.clearScreen();
}


