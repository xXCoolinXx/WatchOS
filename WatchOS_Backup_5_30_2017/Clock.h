#include "App.h"
#include "Events.h"
#include "Rect.h"
//tells time, is a stopwatch, and allows for the selection of games
class Clock : public App {
    Rect changeTime{display.width() - 51, 40, 50, 10};
    //Hold time for stopwatch
    byte swhold = 0;
    //Wether or not the clock setTime mode is on
    bool setTime = false;
    //When changing time, the place where it is changing (ie when changing minute, current place is 2)
    byte current_place = 0;
    //whether or not to start the stopwatch
    bool startSW = 1;
    //hold time for setting time
    //byte specialhold = 0;
    //current app display
    byte button = 0;
    //cursor coords
    Point Cursor{0,44};
    //time
    tmElements_t tm;
    //last time(for stopwatch)
    struct stopwatch {
      byte Second;
      byte Minute;
      byte Hour;
    };

    tmElements_t sw;
    tmElements_t ltm;
    //adds to the current place variable
    void addToCurrentPlace(Direction way);
    //adds to the currentTime variable
    void addToCurrentTime(Direction way);
    //prints 2 digits with a zero prefixing if number isnt in tens
    void print2(byte number);
    //changes font based on current place
    void blinky(byte currentPlace);
  public:
    //function for when the special button isnt being pressed
    void Specialholdoff();
    //reads time
    void Read();
    //writes time
    void Write();
    //function for up key
    void Up();
    //function for down key
    void Down();
    //function for left key
    void Left();
    //function for right key
    void Right();
    //function for special key
    void Special();
    //displays the stuff
    void displayAll();
    void Toggle();
    Clock();
};


