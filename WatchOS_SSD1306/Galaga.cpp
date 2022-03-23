#include "Galaga.h"
extern bool lastSpecial;
const PROGMEM byte aship[] {
  0x00, 0x40, 0x00,
  0x00, 0x40, 0x00,
  0x00, 0xe0, 0x00,
  0x08, 0xa2, 0x00,
  0x08, 0xa2, 0x00,
  0x09, 0xb2, 0x00,
  0x8b, 0xba, 0x20,
  0x8f, 0x5e, 0x20,
  0x97, 0x5d, 0x20,
  0xae, 0xee, 0xa0,
  0xdd, 0xf7, 0x60,
  0xb7, 0xfd, 0xa0,
  0xe6, 0x4c, 0xe0,
  0xc0, 0x40, 0x60,
  0x80, 0x40, 0x20
};
const PROGMEM byte enemy[] {
  0x87, 0xc2,
  0xe6, 0xce,
  0x7e, 0xfc,
  0x1e, 0xf0,
  0xea, 0xae,
  0xb4, 0x5a,
  0x5e, 0xf4,
  0xcc, 0x66,
  0x62, 0x8c,
  0x32, 0x98,
  0x19, 0x30,
  0x01, 0x00
};
Galaga::Galaga() {

  for (int i = 0; i < Count; i++) {
    shots[i].a = Point{255, 255};
    shots[i].b = Point{255, 255};
    shots[i].init = false;
  }
}
void Galaga::Up() {

}
void Galaga::Down() {

}
void Galaga::Left() {
  ship.x -= 3;
  if (ship.x > 230) {
    ship.x = 0;
  }
  delay(1);
}
void Galaga::Right() {
  ship.x += 3;
  if (ship.x > (display.width() - 1 - 19)) {
    ship.x = (display.width() - 1 - 19);
  }
  delay(1);
}
void Galaga::Special() {
  if (!lastSpecial) {
    for (int i = 0; i < Count; i++) {
      if (shots[i].init == false) {
        shots[i].a = Point{ship.x + 9, ship.y};
        shots[i].b = Point{ship.x + 9, ship.y + 5};
        shots[i].init = true;
        break;
      }
    }
  }
}
void Galaga::Specialholdoff() {

}
void Galaga::displayAll() {
  display.drawBitmap(ship.x, ship.y, aship, ship.w, ship.h, WHITE);
  display.drawBitmap(0, 0, enemy, 15, 12, WHITE);
  display.drawLine(0, 54, display.width(), 54, WHITE);
  for (int i = 0; i < 15; i++) {
    if (shots[i].init == true) {
      shots[i].draw();

      shots[i].a.y--;
      shots[i].b.y--;
      if (shots[i].a.y == 0) {
        shots[i].init = false;
      }
    }
  }
}


