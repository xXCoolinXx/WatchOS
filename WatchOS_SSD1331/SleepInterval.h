#pragma once
#include <Arduino.h>
#include <avr/sleep.h>
#include <avr/wdt.h>

void wakeUpNow();
class SleepInterval { 
    void(*preSleep)();
    short sleepTime = 2400;
    byte currentMin = 1;
    byte currentSec = 1;
    byte whenToSleepMin = 1;
    byte whenToSleepSec = 1;
    bool reset = true;
  public: 
    SleepInterval(void(*preSleep_)(), short sleepTime_);
    void loopCode(byte acurrentMin, byte acurrentSec);
    void resetSleep();
    void sleepInterval();
    static bool disableSleepCycle;
};


