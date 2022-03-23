#include <EEPROM.h>
#include <TimeAlarms.h>
//#include "Sleep.h"
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
//extern Sleep sleeper;
const byte PROGMEM flashlight_icon[]
{
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x00, 0x0c, 0x00,
  0x00, 0x1d, 0xc0,
  0x3f, 0xfd, 0xc0,
  0x3f, 0xfd, 0xc0,
  0x3f, 0xfd, 0xc0,
  0x3f, 0xfd, 0xc0,
  0x00, 0x1d, 0xc0,
  0x00, 0x0c, 0x00,
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x00, 0x00, 0x00
};
const byte PROGMEM clock_icon[]
{
  0x3f, 0x80,
  0x40, 0x40,
  0x84, 0x20,
  0x84, 0x20,
  0x84, 0x20,
  0x87, 0x20,
  0x80, 0x20,
  0x80, 0x20,
  0x80, 0x20,
  0x40, 0x40,
  0x3f, 0x80
};
//icon for galaga
const byte PROGMEM maze_icon[]
{
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
const byte PROGMEM galaga_icon[]
{
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
const unsigned char PROGMEM paint_icon []
{
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
const byte PROGMEM pacman_icon []
{
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
const unsigned char PROGMEM pong_icon []
{
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
const unsigned char PROGMEM cursOR[]
{
  0xe0,
  0xc0,
  0xa0,
  0x10
};
//-----------Charge related icons-------------------
const unsigned char PROGMEM full[]
{
  0xff, 0xff, 0x80,
  0xff, 0xfe, 0xc0,
  0xff, 0xfe, 0xc0,
  0xff, 0xfe, 0xc0,
  0xff, 0xfe, 0xc0,
  0xff, 0xfe, 0xc0,
  0xff, 0xff, 0x80
};
const unsigned char PROGMEM half[]
{
  0xff, 0xff, 0x80,
  0xff, 0xc0, 0xc0,
  0xff, 0xc0, 0xc0,
  0xff, 0xc0, 0xc0,
  0xff, 0xc0, 0xc0,
  0xff, 0xc0, 0xc0,
  0xff, 0xff, 0x80
};
const unsigned char PROGMEM dead[]
{
  0xff, 0xff, 0x80,
  0x80, 0x00, 0xc0,
  0x80, 0x00, 0xc0,
  0x80, 0x00, 0xc0,
  0x80, 0x00, 0xc0,
  0x80, 0x00, 0xc0,
  0xff, 0xff, 0x80
};
//------------------------------------------
const byte PROGMEM X[]
{
  0x3c,
  0x99,
  0xc3,
  0xe7,
  0xe7,
  0xc3,
  0x99,
  0x3c
};
//print3 digits
void print3(byte anum) {
  //Check if it is less than 100, and if so, print a 0
  if (anum < 100) {
    display.print(F("0"));
  }
  //Check if it is less than 10 , and if so, print a 0
  if (anum < 10) {
    display.print(F("0"));
  }
  //print the actual number
  display.print(anum);
}

//print2 digits
void Clock::print2(byte number) {
  //If it is less than 10, print a 0
  if (number >= 0 && number < 10) {
    display.print(0);
  }
  //print the number
  display.print(number);
}
//cursor speed
#define val 2
//tells current place when setting time
void Clock::blinky(byte currentPlace) {
  //Check if the current place allows for the time to be lit up
  if (current_place == currentPlace && set_Time == true) {
    display.setTextColor(BLACK, WHITE);
  }
}
void Clock::highlightTimer(byte place) {
  if (place == menuSetPlace && Set) {
    display.setTextColor(BLACK, WHITE);
  }
}
void Clock::Up() {
  if (!clockFullScreen) {
    if (Set && !lastUp) {
      if (timerAlarm == 1) {
        if (menuSetPlace == 0) {
          timer.Hour++;
          if (timer.Hour == 100) {
            timer.Hour = 0;
          }
        }
        if (menuSetPlace == 1) {
          timer.Minute++;
          if (timer.Minute == 60) {
            timer.Minute = 0;
          }
        }
        if (menuSetPlace == 2) {
          timer.Second++;
          if (timer.Second == 60) {
            timer.Second = 0;
          }
        }
      }
    }
    //Add to the time if the set_Time variable is true
    if (set_Time && !lastUp && !Set) {
      addToCurrentTime(up);
    }
    //Otherwise, move the cursor up
    else if (!set_Time && !Set) {
      Cursor.y -= val;
      if (Cursor.y > 230) {
        Cursor.y = 0;
      }
    }
  }
}
void Clock::Down() {
  if (!clockFullScreen) {
    if (Set && !lastDown) {
      if (timerAlarm == 1) {
        if (menuSetPlace == 0) {
          timer.Hour--;
          if (timer.Hour == 255) {
            timer.Hour = 99;
          }
        }
        if (menuSetPlace == 1) {
          timer.Minute--;
          if (timer.Minute == 255) {
            timer.Minute = 59;
          }
        }
        if (menuSetPlace == 2) {
          timer.Second--;
          if (timer.Second == 255) {
            timer.Second = 59;
          }
        }
      }
    }
    //Decrease the current selected time by one if the set_Time variable is true
    if (set_Time && !lastDown) {
      addToCurrentTime(down);
    }
    //Otherwise, move the cursor down
    if (!set_Time && !Set) {
      if (!(Cursor.y + val + 4 >= 50)) {
        Cursor.y += val;
      }
    }
  }
}
void Clock::Left() {
  if (!clockFullScreen) {
    //
    if (Set && !lastLeft) {
      menuSetPlace--;
      if (menuSetPlace == 255) {
        menuSetPlace = 2;
      }
    }
    if (set_Time && lastLeft) {
      addToCurrentPlace(left);
    }
    if (set_Time == false && Set == false) {
      Cursor.x -= val;
      if (Cursor.x > 230) {
        Cursor.x = 0;
        delay(100);
      }
    }
  }
}
void Clock::Right() {
  if (!clockFullScreen) {
    if (Set && !lastRight) {
      menuSetPlace++;
      if (menuSetPlace == 3) {
        menuSetPlace = 0;
      }
    }
    if ( set_Time == true && lastRight == false) {
      addToCurrentPlace(right);
    }
    if (!set_Time && !Set) {
      Cursor.x += val;
      if (Cursor.x + 4 > display.width()/*display.width()*/ - 1) {
        Cursor.x = display.width() - 5;
        delay(100);
      }
    }
  }
}
const short Alarm_Notes[] PROGMEM = {
  2093, 2093, 0, 2093, 2093, 0, 2093, 2093, 0, 2093, 2093, 0, 2093, 2093, 2093, 2093, 0, 2093
};
const short Alarm_Durations[] PROGMEM = {
  4, 4, 8, 4, 4, 8,  4, 4, 8, 4, 4, 8, 4, 4, 4, 4, 16, 1
};

void alarm()
{

  // iterate over the notes of the Alarm_Notes:
  for (byte thisNote = 0; thisNote < 18; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    short noteDuration = 1000 / pgm_read_word(&Alarm_Durations[thisNote]);
    tone(1, pgm_read_word(&Alarm_Notes[thisNote]), noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    short pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(1);
  }

}
void Clock::Special() {
  if (!clockFullScreen) {
    if (set_Time == false) {
      //Clock button
      if (Rect{0, 38, 11, 11} .includes(Cursor) && ta == false) {
        ta = true;
      }
      //X button
      if (Rect{display.width() - 11, 0, 10, 10} .includes(Cursor) && ta == true) {
        ta = false;
        timerAlarm = 0;
        Set = false;
        menuSetPlace = 0;
      }

      if (ta && timerAlarm == 0) {
        //Timer settings button
        if (Rect{0, 0, 31, 9} .includes(Cursor)) {
          timerAlarm = 1;
        }
        //Alarm settings button
        if (Rect{0, 10, 31, 9} .includes(Cursor)) {
          timerAlarm = 2;
        }
        //Set Time Button
        if (Rect{0, 20, 49, 9} .includes(Cursor)) {
          timerAlarm = 3;
          set_Time = true;
          Cursor.x =  (display.width() - 7) / 2;
          Cursor.y = 44;
          ta = false;
          timerAlarm = 0;
        }
        //Stopwatch Button
        if (Rect{0, 30, 55, 9} .includes(Cursor)) {
          timerAlarm = 4;
          startSW = 0;
          ta = false;
          timerAlarm = 0;
          swOn = true;
        }

      }
      else if (ta && timerAlarm == 1) {
        if (!lastSpecial && Rect{(display.width() - 62) / 3 * 2 + 31, 20, 31, 9} .includes(Cursor)) {
          timerOn = !timerOn;
          if (timerOn) {
            timer.Second_activateTime = tm.Second + timer.Second;
            timer.Minute_activateTime = tm.Minute + timer.Minute;
            timer.Hour_activateTime = tm.Hour + timer.Hour;
            if (timer.Second_activateTime > 59) {
              timer.Minute_activateTime += (timer.Second_activateTime - timer.Second_activateTime % 60) / 60;
              timer.Second_activateTime -= (timer.Second_activateTime - timer.Second_activateTime % 60);
            }
            if (timer.Minute_activateTime > 59) {
              timer.Hour_activateTime += (timer.Minute_activateTime - timer.Minute_activateTime % 60) / 60;
              timer.Minute_activateTime -= (timer.Minute_activateTime - timer.Minute_activateTime % 60);
            }
          }
          else {
            rewriteTimer = true;
            int timer_toSeconds;
            timer_toSeconds = timer.Second_activateTime + timer.Minute_activateTime * 60 + timer.Hour_activateTime * 60 * 60;
            int tm_toSeconds;
            tm_toSeconds = tm.Second + tm.Minute * 60 + tm.Hour * 60 * 60;
            int difference = timer_toSeconds - tm_toSeconds;
            timer.Second = difference       % 60;
            timer.Minute = difference       / 60;
            timer.Hour   = timer.Minute / 60;
          }
        }
      }

    }

    if (!lastSpecial) {
      //End button
      if (Rect{display.width() - 9, 41, 7, 9} .includes(Cursor)) {
        sw.Second = 0;
        sw.Minute = 0;
        sw.Hour = 0;
        startSW = 1;
        swOn = false;
      }
      //Start Stop button (stopwatch)
      if (Rect{display.width() - 69, 41, 7, 9} .includes(Cursor) && swOn) {
        if (startSW == 1) {
          startSW = 0;
        }
        else if (startSW == 0) {
          startSW = 1;
        }
      }
      if (Rect{display.width() / 2 - (47 / 2) + 49, 31, 25, 9} .includes(Cursor)) {
        EEPROM.write(0, timer.Hour);
        EEPROM.write(1, timer.Minute);
        EEPROM.write(2, timer.Second);
      }
    }
  }
  if (Rect{(display.width() - 27) / 2, 31, 9, 7} .includes(Cursor) && !lastSpecial) {
    button--;
    if (button == 255) {
      button = 2;
    }
  }
  if (Rect{(display.width() - 27) / 2 + 17, 31, 9, 7} .includes(Cursor) && !lastSpecial) {
    if (button + 1 != 3) {
      button++;
    }
    else {
      button = 0;
    }
  }

  if (Rect{(display.width() - 62) / 3 * 2 + 65, 20, 19, 9} .includes(Cursor) && !lastSpecial && timerOn) {
    timerOn = false;
    timer.Hour = EEPROM.read(0);
    timer.Minute = EEPROM.read(1);
    timer.Second = EEPROM.read(2);
  }

}
void Clock::displayAll() {

  display.setTextColor(WHITE);

  { //Display Time

    display.drawLine(0, 50, display.width(), 50, WHITE);
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

  } //Display time

  stopwatch();

#define space (display.width() - 80) / 3
  Rect apps[4] { {0, 5, 20, 20}, {20 + space, 5, 20, 20}, {(20 + space) * 2, 5, 20, 20}, {(20 + space) * 3, 5, 20, 20} };

  //display.drawRect(changeTime.x, changeTime.y, changeTime.w, changeTime.h, WHITE);
  //display.setCursor(changeTime.x + 1, changeTime.y + 1);
  //display.setTextColor(BLACK, WHITE);
  //display.print(F("Set Time"));
  //display.setTextColor(WHITE);

  for (int i = 0; i < 4; i++) {
    display.drawRect(apps[i].x, apps[i].y, apps[i].w, apps[i].h, WHITE);


    if (apps[i].includes(Cursor) && lastSpecial == true && ta == false) {
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
        if (i == 1) {
          Game::gameSelect = 5;
        }
      }
      Game::select();
      currentState = 0;
    }
  }
  display.fillRoundRect( (display.width() - 27) / 2, 31, 9, 7, 1, WHITE);
  display.setCursor( (display.width() - 27) / 2 + 2, 31);
  display.setTextColor(BLACK);
  display.println(F("-"));
  display.setTextColor(WHITE);
  display.setCursor( (display.width() - 27) / 2 + 11, 31);
  display.println(button + 1);
  display.setTextColor(BLACK);
  display.fillRoundRect( (display.width() - 27) / 2 + 17, 31, 9, 7, 1, WHITE);
  display.setCursor((display.width() - 27) / 2 + 19, 31);
  display.println(F("+"));
  display.setTextColor(WHITE);
  if (button == 0) {

    display.drawBitmap(apps[0].x + 1, apps[0].y + 1, paint_icon, 18, 18, WHITE);
    display.drawBitmap(apps[1].x + 1, apps[1].y + 1, pong_icon, 18, 18, WHITE);
    display.drawBitmap(apps[2].x + 1, apps[2].y + 1, pacman_icon, 18, 18, WHITE);
    display.drawBitmap(apps[3].x + 1, apps[3].y + 1, galaga_icon, 18, 18, WHITE);
  }
  if (button == 1) {
    display.drawBitmap(apps[0].x + 1, apps[0].y + 1, maze_icon, 18, 18, WHITE);
    display.drawBitmap(apps[1].x + 1, apps[1].y + 1, flashlight_icon, 18, 18, WHITE);

  }
  if (button == 2) {

  }

  //Rect{0,0,20,7}.draw();
  if (ta == false) {
    display.setTextColor(BLACK, WHITE);
    display.drawBitmap(0, 38, clock_icon, 11, 11, WHITE);

    display.setTextColor(WHITE);
  }
  if (ta == true) {
    display.fillRect(0, 0, display.width(), 40, BLACK);
    Rect{display.width() - 11, 0, 10, 10} .draw();
    display.drawBitmap(display.width() - 10, 1, X, 8, 8, BLACK);

    if (timerAlarm == 0) {
      display.drawLine(0, 0, 0, 38, WHITE);

      display.setTextColor(BLACK);

      display.fillRoundRect(0, 0, 31, 9, 1, WHITE);
      display.setCursor(1, 1);
      display.print(F("Timer"));

      display.fillRoundRect(0, 10, 31, 9, 1, WHITE);
      display.setCursor(1, 11);
      display.print(F("Alarm"));

      display.fillRoundRect(0, 20, 49, 9, 1, WHITE);
      display.setCursor(1, 21);
      display.print(F("Set Time"));

      display.fillRoundRect(0, 30, 55, 9, 1, WHITE);
      display.setCursor(1, 31);
      display.setTextColor(BLACK);
      display.print(F("Stopwatch"));

      display.setTextColor(WHITE);
    }
    if (timerAlarm == 1) {
      display.setCursor(display.width() / 2 - 14, 0);
      display.print(F("Timer"));
      display.fillRoundRect((display.width() - 62) / 3, 20, 31, 9, 1, WHITE);
      display.fillRoundRect((display.width() - 62) / 3 * 2 + 31, 20, 31, 9, 1, WHITE);
      display.setTextColor(BLACK);
      display.setCursor((display.width() - 62) / 3 + 1, 21);
      display.print(F(" Set "));
      if (lastSpecial && Rect{(display.width() - 62) / 3, 20, 31, 9} .includes(Cursor)) {
        Set = true;
      }

      display.setCursor((display.width() - 62) / 3 * 2 + 32, 21);
      if (!timerOn) {
        display.print(F("Start"));
      }
      else {
        display.print(F("Stop "));
      }

      if (timerOn) {
        display.fillRect((display.width() - 62) / 3 * 2 + 65, 20, 19, 9,WHITE);
        display.setCursor((display.width() - 62) / 3 * 2 + 66, 21);
        display.println("End");
        display.setTextColor(WHITE);
      }
      display.setTextColor(WHITE);
      display.setCursor(display.width() / 2 - (47 / 2), 31);
      highlightTimer(0);   
      print2(timer.Hour);
      display.setTextColor(WHITE);
      display.print(":");
      highlightTimer(1);
      print2(timer.Minute);
      display.setTextColor(WHITE);
      display.print(":");
      highlightTimer(2);
      print2(timer.Second);
      display.setTextColor(WHITE);
      display.fillRoundRect(display.width() / 2 - (47 / 2) + 49, 31, 25, 9, 1, WHITE);
      display.setCursor(display.width() / 2 - (47 / 2) + 50, 32);
      display.setTextColor(BLACK);
      display.println("Save");
      display.setTextColor(WHITE);
      timerTime countdown;

      int timer_toSeconds;
      timer_toSeconds = timer.Second_activateTime + timer.Minute_activateTime * 60 + timer.Hour_activateTime * 60 * 60;
      int tm_toSeconds;
      tm_toSeconds = tm.Second + tm.Minute * 60 + tm.Hour * 60 * 60;
      int difference = timer_toSeconds - tm_toSeconds;
      countdown.Second = difference       % 60;
      countdown.Minute = difference       / 60;
      countdown.Hour   = countdown.Minute / 60;
      if (timerOn) {
//        sleeper.resetSleep();
        display.setCursor(display.width() / 2 - (47 / 2), 39);
        print2(countdown.Hour);
        display.setTextColor(WHITE);
        display.print(":");
        print2( countdown.Minute);
        display.setTextColor(WHITE);
        display.print(":");
        print2( countdown.Second);
      }

    }
    if (timerAlarm == 2) {
      display.setCursor(display.width() / 2 - 14, 0);
      display.print(F("Alarm"));
      
    }
  }
  display.drawBitmap(Cursor.x, Cursor.y, cursOR, 4, 4, WHITE);
  if (clockFullScreen == true) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor( 0/*(display.width()-111)/2*/, (display.height() - 14) / 2 );

    if (tm.Hour > 12) {
      print2(tm.Hour - 12);
    } else {
      print2(tm.Hour);
    }
    display.print(F(":"));
    print2(tm.Minute);
    display.print(":");
    print2(tm.Second);
    display.setTextSize(1);

    if (tm.Hour > 12) {
      display.println(F("PM"));
    }
    else {
      display.println(F("AM"));
    }
  }
  if (tm.Second == timer.Second_activateTime && tm.Minute == timer.Minute_activateTime && tm.Hour == timer.Hour_activateTime && timerOn) {
    alarm();
    timerOn = false;
    if (rewriteTimer) {
      timer.Hour = EEPROM.read(0);
      timer.Minute = EEPROM.read(1);
      timer.Second = EEPROM.read(2);
      rewriteTimer = false;
    }
    timer.Second_activateTime = 0;
    timer.Minute_activateTime = 0;
    timer.Hour_activateTime = 0;
  }
  //Clear display
  display.drawBitmap(Cursor.x, Cursor.y, cursOR, 4, 4, BLACK);
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
  //yield();
}
void Clock::Write() {
  if (set_Time == true) {
    RTC.write(tm);
  }
  //yield();
}
void Clock::Specialholdoff() {

  //specialhold = 0;

}
Clock::Clock() {
  Cursor.x = (display.width() - 7) / 2;
  timer.Hour = EEPROM.read(0);
  timer.Minute = EEPROM.read(1);
  timer.Second = EEPROM.read(2);
}
void Clock::Toggle() {
  if (!ta && timerAlarm == 0 && !Set && !set_Time && lastToggle) {
    toggleHold++;
    if (toggleHold == 40) {
      toggleHold = 0;
      clockFullScreen = true;
    }
  }
  if (!ta && timerAlarm == 0 && !Set && !set_Time && !lastToggle && clockFullScreen) {
    clockFullScreen = false;
  }
  if (ta && timerAlarm == 0 && !lastToggle && !Set) {
    ta = false;
  }
  else if (ta && timerAlarm != 0 && !lastToggle && !Set) {
    timerAlarm = 0;
  }
  else if (Set) {
    Set = false;
  }
  if (set_Time == true) {
    set_Time = false;
  }
  if (Set == true) {
    Set = false;
  }
}
void Clock::stopwatch() {
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
  if (sw.Second != 0 || sw.Minute != 0 || sw.Hour != 0) {
//    sleeper.resetSleep();
    display.setTextSize(1);
    display.setCursor(display.width() - 59, 40);
    print2(sw.Hour);
    display.print(F(":"));
    print2(sw.Minute);
    display.print(F(":"));
    print2(sw.Second);

    display.fillRect(display.width() - 69, 41, 7, 9, WHITE);
    display.setCursor(display.width() - 68, 42);
    display.setTextColor(BLACK, WHITE);
    display.println(F("S"));
    display.setTextColor(WHITE);

    display.fillRect(display.width() - 9, 41, 7, 9, WHITE);
    display.setCursor(display.width() - 8, 42);
    display.setTextColor(BLACK, WHITE);
    display.println(F("E"));
    display.setTextColor(WHITE);

  }
}

Clock clock;
