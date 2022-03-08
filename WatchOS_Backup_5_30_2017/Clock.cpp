//include the clock.h file where everything is defined to implement it
#include "Clock.h"
//Get the easy class to make a rectangle
#include "Rect.h"
//get previous of everything for doing things
extern bool lastLeft;
extern bool lastRight;
extern bool lastUp;
extern bool lastDown;
extern bool lastSpecial;
extern bool currentState;
extern bool lastToggle;

//icon for galaga
const byte PROGMEM maze_icon[] {
  0xff, 0xff, 0xc0,
  0x84, 0x02, 0x40,
  0x84, 0x02, 0x40,
  0x9c, 0x02, 0x40,
  0x90, 0x63, 0xc0,
  0x90, 0x60, 0x40,
  0x9c, 0x60, 0x40,
  0x80, 0x20, 0x40,
  0x80, 0x3e, 0x40,
  0x80, 0x00, 0x40,
  0x9f, 0x00, 0x40,
  0x91, 0x00, 0x40,
  0x97, 0x1e, 0x40,
  0x94, 0x10, 0x40,
  0x94, 0x10, 0x40,
  0x94, 0x70, 0x40,
  0x94, 0x40, 0x40,
  0xf7, 0xff, 0xc0
};
const byte PROGMEM galaga_icon[] {
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x00, 0x40, 0x00,
  0x00, 0x40, 0x00,
  0x00, 0xe0, 0x00,
  0x08, 0xa2, 0x00,
  0x08, 0xa2, 0x00,
  0x09, 0xb2, 0x00,
  0x4b, 0xba, 0x40,
  0x4f, 0x5e, 0x40,
  0x57, 0x5d, 0x40,
  0x6e, 0xee, 0xc0,
  0x5d, 0xf7, 0x40,
  0x77, 0xfd, 0xc0,
  0x66, 0x4c, 0xc0,
  0x40, 0x40, 0x40,
  0x40, 0x40, 0x40
};
//icon for paint
const unsigned char PROGMEM paint_icon [] {
  0x00, 0x00, 0x00,
  0x01, 0xc0, 0x00,
  0x01, 0xc0, 0x00,
  0x01, 0xc0, 0x00,
  0x01, 0xc0, 0x00,
  0x01, 0xc0, 0x00,
  0x01, 0xc0, 0x00,
  0x01, 0xc0, 0x00,
  0x01, 0xc0, 0x00,
  0x01, 0xc0, 0x00,
  0x03, 0xf0, 0x00,
  0x03, 0xf0, 0x00,
  0x03, 0xf0, 0x00,
  0x03, 0xf8, 0x00,
  0x03, 0xfc, 0x00,
  0x03, 0xfc, 0x00,
  0x01, 0xfe, 0x00,
  0x00, 0x00, 0x00
};
//icon for pacman
const byte PROGMEM pacman_icon [] {
  0x0f, 0xe0, 0x00,
  0x3f, 0xf8, 0x00,
  0x7f, 0xf8, 0x00,
  0x7f, 0xfc, 0x00,
  0x3f, 0xfc, 0x00,
  0x03, 0xfc, 0x00,
  0x00, 0xfc, 0x00,
  0x03, 0xfc, 0x00,
  0x3f, 0xfc, 0x00,
  0x7f, 0xfc, 0x00,
  0x7f, 0xf8, 0x00,
  0x3f, 0xf8, 0x00,
  0x0f, 0xf0, 0xc0,
  0x00, 0x03, 0xc0,
  0x00, 0x07, 0xc0,
  0x00, 0x07, 0x00,
  0x00, 0x07, 0x00,
  0x00, 0x07, 0x00
};
//icon for pong
const unsigned char PROGMEM pong_icon [] {
  0x00, 0x00, 0x00,
  0x60, 0x00, 0x00,
  0x60, 0x00, 0x00,
  0x60, 0x00, 0x00,
  0x60, 0x00, 0x00,
  0x60, 0x00, 0x00,
  0x60, 0x01, 0x80,
  0x60, 0x01, 0x80,
  0x60, 0x19, 0x80,
  0x60, 0x3d, 0x80,
  0x00, 0x3d, 0x80,
  0x00, 0x19, 0x80,
  0x00, 0x01, 0x80,
  0x00, 0x01, 0x80,
  0x00, 0x01, 0x80,
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00
};
//smaller windows like cursor
const unsigned char PROGMEM cursOR[] {
  0xe0,
  0xc0,
  0xa0,
  0x10
};
//-----------Charge related icons-------------------
const unsigned char PROGMEM full[] {
  0xff, 0xff, 0x80,
  0xff, 0xfe, 0xc0,
  0xff, 0xfe, 0xc0,
  0xff, 0xfe, 0xc0,
  0xff, 0xfe, 0xc0,
  0xff, 0xfe, 0xc0,
  0xff, 0xff, 0x80
};
const unsigned char PROGMEM half[] {
  0xff, 0xff, 0x80,
  0xff, 0xc0, 0xc0,
  0xff, 0xc0, 0xc0,
  0xff, 0xc0, 0xc0,
  0xff, 0xc0, 0xc0,
  0xff, 0xc0, 0xc0,
  0xff, 0xff, 0x80
};
const unsigned char PROGMEM dead[] {
  0xff, 0xff, 0x80,
  0x80, 0x00, 0xc0,
  0x80, 0x00, 0xc0,
  0x80, 0x00, 0xc0,
  0x80, 0x00, 0xc0,
  0x80, 0x00, 0xc0,
  0xff, 0xff, 0x80
};
//------------------------------------------

//print3 digits
void print3(byte anum) {
  if (anum < 100) {
    display.print(F("0"));
  }
  if (anum < 10) {
    display.print(F("0"));
  }
  display.print(anum);
}

//print2 digits
void Clock::print2(byte number) {
  if (number >= 0 && number < 10) {
    display.print(0);
  }
  display.print(number);
}
//cursor speed
#define val 2
//tells current place when setting time
void Clock::blinky(byte currentPlace) {
  if (current_place == currentPlace && setTime == true) {
    display.setTextColor(BLACK, WHITE);
  }
}
void Clock::Up() {
  if (setTime == true && lastUp == false) {
    addToCurrentTime(up);
  }
  if (setTime == false) {
    Cursor.y -= val;
    if (Cursor.y > 230) {
      Cursor.y = 0;
    }
  }
}
void Clock::Down() {
  if (setTime == true && lastDown == false) {
    addToCurrentTime(down);
  }
  if (setTime == false) {
    if (!(Cursor.y + val + 4 >= 50)) {
      Cursor.y += val;
    }
  }
}
void Clock::Left() {
  if (setTime == true && lastLeft == false) {
    addToCurrentPlace(left);
  }
  if (setTime == false) {
    Cursor.x -= val;
    if (Cursor.x > 230) {
      Cursor.x = 0;
      button--;
      if (button > 2) {
        button = 2;
      }
      delay(100);
    }
  }

}
void Clock::Right() {

  if ( setTime == true && lastRight == false) {
    addToCurrentPlace(right);
  }
  if (setTime == false) {
    Cursor.x += val;
    if (Cursor.x + 4 > display.width()/*display.width()*/ - 1) {
      Cursor.x = display.width() - 5;
      button++;
      if (button > 2) {
        button = 0;
      }
      delay(100);
    }
  }
}
void Clock::Special() {
  if (setTime == false) {
    if (changeTime.includes(Cursor)) {
      setTime = true;
      Cursor.x =  (display.width() - 7) / 2;
      Cursor.y = 44;
    }
    if (Rect{ ((display.width() - 7) / 2) - 13, 31, 9, 9 } .includes(Cursor)) {
      button = 0;
    }
    if (Rect{ ((display.width() - 7) / 2) - 3 , 31, 9, 9 } .includes(Cursor)) {
      button = 1;
    }
    if (Rect{ ((display.width() - 7) / 2) + 7 , 31, 9, 9 } .includes(Cursor)) {
      button = 2;
    }
  }

  if (lastSpecial == false) {
    if (Rect{50, 41, 7, 9} .includes(Cursor)) {
      sw.Second = 0;
      sw.Minute = 0;
      sw.Hour = 0;
      startSW = 1;
    }
  }
}
void Clock::displayAll() {

  display.setTextColor(WHITE);

  display.drawLine(0, 50, display.width(), 50, WHITE);
  //byte sp = (display.width()-69)/3;
  display.setCursor(0, 54);
  display.setTextSize(1);

  blinky(0);
  if (tm.Hour > 12) {
    print2(tm.Hour - 12);
  } else {
    print2(tm.Hour);
  }
  display.setTextColor(WHITE);
  display.print(F(":"));
  blinky(1);
  print2(tm.Minute);
  display.setTextColor(WHITE);
  /*
    display.print(":");
    blinky(2);
    print2(tm.Second);

    display.setTextColor(WHITE);
  */
  display.setCursor(display.width() / 2 - 1 - 7, 54);
  //display.print(" ");
  blinky(2);
  switch (tm.Wday) {
    case 1: display.print(F("Su")); break;
    case 2: display.print(F("Mo")); break;
    case 3: display.print(F("Tu")); break;
    case 4: display.print(F("We")); break;
    case 5: display.print(F("Th")); break;
    case 6: display.print(F("Fr")); break;
    case 7: display.print(F("Sa")); break;
    default:

      break;
  }
  display.setTextColor(WHITE);
  display.print(F(" "));
  display.setCursor(display.width() - 30, 54);
  blinky(3);
  print2(tm.Month);
  display.setTextColor(WHITE);
  display.print(F("/"));
  blinky(4);
  print2(tm.Day);
  display.setTextColor(WHITE);
  display.print(F(" "));

  if (startSW == 0) {
    if (ltm.Second != tm.Second || ltm.Minute != tm.Minute || ltm.Hour != tm.Hour) {
      sw.Second ++;
      if (sw.Second > 59) {
        sw.Minute++;
        sw.Second = 0;
      }
      if (sw.Minute > 59) {
        sw.Hour++;
        sw.Minute = 0;
      }
      ltm = tm;
//      ltm.Second = tm.Second;
//    ltm.Minute = tm.Minute;
//    ltm.Hour = tm.Hour;
    }
  }
  else if (startSW == 1) {
    ltm = tm;
//    ltm.Second = tm.Second;
//    ltm.Minute = tm.Minute;
//    ltm.Hour = tm.Hour;
  }
  else if (swhold != 4) {
    ltm = tm;
//    ltm.Second = tm.Second;
//    ltm.Minute = tm.Minute;
//    ltm.Hour = tm.Hour;
  }
  if (sw.Second != 0 || sw.Minute != 0 || sw.Hour != 0) {
    display.setTextSize(1);
    display.setCursor(0, 40);
    print2(sw.Hour);
    display.print(F(":"));
    print2(sw.Minute);
    display.print(F(":"));
    print2(sw.Second);
  }



  #define space (display.width() - 80) / 3
  Rect apps[4]{ {0, 5, 20, 20}, {20 + space, 5, 20, 20}, {(20 + space) * 2, 5, 20, 20}, {(20 + space) * 3, 5, 20, 20} };

  display.drawRect(changeTime.x, changeTime.y, changeTime.w, changeTime.h, WHITE);
  display.setCursor(changeTime.x + 1, changeTime.y + 1);
  display.setTextColor(BLACK, WHITE);
  display.print(F("Set Time"));
  display.setTextColor(WHITE);

  for (int i = 0; i < 4; i++) {
    display.drawRect(apps[i].x, apps[i].y, apps[i].w, apps[i].h, WHITE);


    if (apps[i].includes(Cursor) && lastSpecial == true) {
      if (button == 0) {
        if (i == 0) {
          Game::gameSelect = 0;
        }
        if (i == 1) {
          Game::gameSelect = 1;
        }
        if (i == 2) {
          Game::gameSelect = 2;
        }
        if (i == 3)
        {
          Game::gameSelect = 3;
        }
      }
      if (button == 1) {
        if (i == 0) {
          Game::gameSelect = 4;
        }
      }
      //Game::select();
      currentState = 0;
    }
  }
  #define buttons ((display.width() - 7) / 2)
  if (button == 0) {
    display.fillCircle(buttons - 10, 34, 3, WHITE);
    display.drawBitmap(apps[0].x + 1, apps[0].y + 1, paint_icon, 18, 18, WHITE);
    display.drawBitmap(apps[1].x + 1, apps[1].y + 1, pong_icon, 18, 18, WHITE);
    display.drawBitmap(apps[2].x + 1, apps[2].y + 1, pacman_icon, 18, 18, WHITE);
    display.drawBitmap(apps[3].x + 1, apps[3].y + 1, galaga_icon, 18, 18, WHITE);
  } else {
    display.drawCircle(buttons - 10, 34, 3, WHITE);
  }
  if (button == 1) {
    display.drawBitmap(apps[0].x + 1, apps[0].y + 1, maze_icon, 18, 18, WHITE);
    display.fillCircle(buttons, 34, 3, WHITE);
  } else {
    display.drawCircle(buttons, 34, 3, WHITE);
  }
  if (button == 2) {
    display.fillCircle(buttons + 10, 34, 3, WHITE);
  } else {
    display.drawCircle(buttons + 10, 34, 3, WHITE);
  }

  if (sw.Minute > 0 || sw.Hour > 0 || sw.Second > 0) {
    display.fillRect(50,41,7,9,WHITE);
    display.setCursor(51, 42);
    display.setTextColor(BLACK, WHITE);
    display.println(F("E"));
    display.setTextColor(WHITE);
  }

  display.drawBitmap(Cursor.x, Cursor.y, cursOR, 4, 4, INVERSE);
}

void Clock::addToCurrentPlace(Direction way) {
  if (way == left) {
    if (current_place != 0) {
      current_place--;
    }
    else {
      current_place = 4;
    }
  }
  else {
    if (current_place != 4) {
      current_place++;
    }
    else {
      current_place = 0;
    }
  }

}
void Clock::addToCurrentTime(Direction way) {
  if (way == up) {
    if (current_place == 0) {
      tm.Hour++;
    }
    if (current_place == 1) {
      tm.Minute++;
    }
    if (current_place == 2) {
      if (tm.Wday != 7) {
        tm.Wday++;
      }
      else {
        tm.Wday = 1;
      }
    }
    if (current_place == 3) {
      tm.Month++;
    }
    if (current_place == 4) {
      tm.Day++;
    }
    if (current_place == 6) {
      tm.Year++;
    }
  }
  if (way == down) {
    if (current_place == 0) {
      tm.Hour--;
    }
    else if (current_place == 1) {
      tm.Minute--;
    }
    if (current_place == 2) {
      if (tm.Wday != 1) {
        tm.Wday--;
      }
      else {
        tm.Wday = 7;
      }
    }
    if (current_place == 3) {
      tm.Month--;
    }
    if (current_place == 4) {
      tm.Day--;
    }
    tm.Year--;
  }
  if (current_place == 6) {
  }
}
void Clock::Read() {
  RTC.read(tm);
}
void Clock::Write() {
  if (setTime == true) {
    RTC.write(tm);
  }
}
void Clock::Specialholdoff() {

  //specialhold = 0;

}
Clock::Clock() {
  Cursor.x = (display.width() - 7) / 2;

}
void Clock::Toggle() {
  if (!setTime && !lastToggle) {
    if (startSW == 1) {
      startSW = 0;
    }
    else {
      startSW = 1;
    }
  }
  if (setTime == true) {
    setTime = false;
  }
  
}
Clock clock;

