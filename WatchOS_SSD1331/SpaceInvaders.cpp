#include "SpaceInvaders.h"

extern bool lastSpecial;
const PROGMEM byte aDestroyer[] {
  0x04, 0x00,
  0x0e, 0x00,
  0x0e, 0x00,
  0x7f, 0xc0,
  0xff, 0xe0,
  0xff, 0xe0,
  0xff, 0xe0
};
const unsigned char InvaderTopGfx [] PROGMEM = {
  B00011000,
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B00100100,
  B01011010,
  B10100101
};

static const unsigned char PROGMEM InvaderMiddleGfx [] =
{
  B00100000, B10000000,
  B00010001, B00000000,
  B00111111, B10000000,
  B01101110, B11000000,
  B11111111, B11100000,
  B10111111, B10100000,
  B10100000, B10100000,
  B00011011, B00000000
};

static const unsigned char PROGMEM InvaderBottomGfx [] = {
  B00001111, B00000000,
  B01111111, B11100000,
  B11111111, B11110000,
  B11100110, B01110000,
  B11111111, B11110000,
  B00111001, B11000000,
  B01100110, B01100000,
  B00110000, B11000000
};
byte AlienWidth[] = {8, 11, 12}; // top, middle ,bottom widths
SpaceInvaders::SpaceInvaders() {

  for (int i = 0; i < Count; i++) {
    shots[i].a = Point{255, 255};
    shots[i].b = Point{255, 255};
    shots[i].init = false;
  }
  //Set alien positions
  for (int across = 0; across < NUM_ALIEN_COLUMNS; across++)  {
    for (int down = 0; down < 3; down++)  {
      Alien[across][down].x = X_START_OFFSET + (across * (LARGEST_ALIEN_WIDTH + SPACE_BETWEEN_ALIEN_COLUMNS)) - down;
      Alien[across][down].y = 0 + (down * SPACE_BETWEEN_ROWS);
      Alien[across][down].w =  AlienWidth[down];
      Alien[across][down].h = 8;
    }
  }
#define SHIELD_Y 50
#define SPACE 12
}
void SpaceInvaders::Up() {

}
void SpaceInvaders::Down() {

}
void SpaceInvaders::Left() {
  Destroyer.x -= 2;
  if (Destroyer.x > 230) {
    Destroyer.x = 0;
  }
  delay(1);
}
void SpaceInvaders::Right() {
  Destroyer.x += 2;
  if (Destroyer.x > (display.width() - 1 - 10)) {
    Destroyer.x = (display.width() - 1 - 10);
  }
  delay(1);
}
void SpaceInvaders::Special() {
  if (!lastSpecial) {
    for (int i = 0; i < Count; i++) {
      if (shots[i].init == false) {
        shots[i].a = Point{Destroyer.x + 6, Destroyer.y};
        shots[i].b = Point{Destroyer.x + 6, Destroyer.y + 4};
        shots[i].init = true;
        break;
      }
    }
  }
}
void SpaceInvaders::enemyFire() {
  byte anyAlive = 0;
  for (int across = 0; across < NUM_ALIEN_COLUMNS; across++)
  {
    for (int down = 0; down < 3; down++)
    {
      if (Alien[across][down].alive == true) {
        anyAlive++;
      }
    }
  }
  if (anyAlive >= 6) {
    for (int i = 0; i < 5; i++) {


      if (enemyShots[i].init == false) {
        bool Alive = false;
        while (!Alive) {
          short c = random(1, NUM_ALIEN_COLUMNS) - 1;
          short r = random(1, NUM_ALIEN_ROWS) - 1;
          if (Alien[c][r].alive) {
            Alive = true;
          }
          c *= 16; c += 6;
          r *= 8 + 1;
          enemyShots[i].a = Point{c + 5, r};
          enemyShots[i].b = Point{c + 5, r - 4};
          enemyShots[i].init = true;

        }
      }
    }
  }
}
void SpaceInvaders::displayAll() {
  enemyFire();
  display.clearScreen();
  display.setCursor(0, Alien[0][2].y + Alien[0][2].h + 5);
  display.println(score);
  display.drawBitmap(Destroyer.x, Destroyer.y, aDestroyer, Destroyer.w, Destroyer.h, WHITE);
  for (int i = 0; i < Count; i++) {
    if (shots[i].b.y <= 5 && shots[i].b.y > 0) {
      shots[i].init = false;
    }
    if (shots[i].init) {
      shots[i].a.y -= 3;
      shots[i].b.y -= 3;
      shots[i].draw();
    }

  }
  for (int i = 0; i < 5; i++) {
    if (enemyShots[i].b.y >= 60) {
      enemyShots[i].init = false;
    }
    if (enemyShots[i].init == true) {
      enemyShots[i].a.y += 2;
      enemyShots[i].b.y += 2;
      enemyShots[i].draw();
      if(Destroyer.intersects(enemyShots[i])) {
        //tone(8, 2093, 2);
      }
    }
  }
  byte anyAlive = 0;

  for (int across = 0; across < NUM_ALIEN_COLUMNS; across++)
  {
    for (int down = 0; down < 3; down++)
    {
      for (int i = 0; i < Count; i++) {
        if (Alien[across][down].intersects(shots[i]) && shots[i].init && Alien[across][down].alive) {
          Alien[across][down].alive = false;
          shots[i].init = false;
          if (down == 0) {
            score += 40;
          }
          if (down == 1) {
            score += 20;
          }
          if (down == 2) {
            score += 10;
          }
        }
      }
      if (Alien[across][down].alive) {
        anyAlive++;
        switch (down)
        {
          case 0:
            display.drawBitmap(Alien[across][down].x, Alien[across][down].y,  InvaderTopGfx, Alien[across][down].w, Alien[across][down].h, GREEN);

            break;
          case 1:

            display.drawBitmap(Alien[across][down].x, Alien[across][down].y,  InvaderMiddleGfx, Alien[across][down].w, Alien[across][down].h, GREEN);
            break;
          default:
            display.drawBitmap(Alien[across][down].x, Alien[across][down].y,  InvaderBottomGfx, Alien[across][down].w, Alien[across][down].h, GREEN);

        }
      }
    }
  }
  if (anyAlive <= 3) {
    for (int across = 0; across < NUM_ALIEN_COLUMNS; across++)
    {
      display.clearScreen();
      display.setCursor(0, 0);
      display.println("You Won!");
      delay(1000);
      display.clearScreen();
      for (int down = 0; down < 3; down++)
      {
        Alien[across][down].alive = true;
      }
    }
  }
  //moveAliens();
  //delay(5);
}
void SpaceInvaders::moveAliens() {
  for (int across = 0; across < NUM_ALIEN_COLUMNS; across++)
  {
    for (int down = 0; down < 3; down++)
    {
      Alien[across][down].x ++;
    }
  }
}



