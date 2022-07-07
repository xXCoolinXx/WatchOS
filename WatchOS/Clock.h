#pragma once
#include "App.h"
#include "Print.h"

#define ROW_SPACE 10
#define NUM_ROWS 3
#define X_SPACE 10

class Kernel;

enum Selection {
  STOPWATCH = ROW_SPACE,
  TIMER = 2 * ROW_SPACE,
  ALARMS = 3 * ROW_SPACE,
};

Selection operator++(Selection& s);
Selection operator--(Selection& s);

enum TimeSelection {
  NOT_EDITING = 1,
  HOUR = 40,
  MINUTE = HOUR + 3 * CHAR_SPACE_W, //=58,
  SECOND = MINUTE + 3 * CHAR_SPACE_W  //=76,
};

TimeSelection operator++(TimeSelection& s);
TimeSelection operator--(TimeSelection& s);

enum AlarmEdit {
  ID = 1, SET,
  HOUR_, MINUTE_,
  SUNDAY = 5, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY=11,
  NOT
};

AlarmEdit operator++(AlarmEdit& s);
AlarmEdit operator--(AlarmEdit& s);

short getX(AlarmEdit a);
short getY(AlarmEdit a);
short getWidth(AlarmEdit a);

class Clock : public App {
  bool just_moved_x = false;
  bool just_moved_y = false;
  Selection current_selection = Selection::STOPWATCH;

  void _clearStopwatchArea(Kernel* kernel);
  void _clearTimerArea(Kernel* kernel);
  void _underline(short x, short y, short num_chars, Kernel* kernel, bool clear = true);
  void _clearAlarmArea(Kernel* kernel);
  //void _drawDOW(

  TimeSelection edit = TimeSelection::NOT_EDITING;
  AlarmEdit alarm_edit = NOT;

  int alarm_number = 0;
  public:
  Clock(Kernel* kernel);

  void run_code(double x, double y, bool special, Kernel* kernel);
  void update_selection(double x, double y, Kernel* kernel);
  String get_name();

  void checkSpecial(double x, double y, bool special, Kernel* kernel);
};
