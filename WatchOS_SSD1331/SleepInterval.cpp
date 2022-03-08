#include "SleepInterval.h"
#include <SPI.h>
#include <Wire.h>
#include <SSD_13XX.h>

extern SSD_13XX display;
bool SleepInterval::disableSleepCycle = true;
void wakeUpNow()
{
  
}

void SleepInterval::loopCode(byte acurrentMin, byte acurrentSec) {
  if (disableSleepCycle) {
    currentMin = acurrentMin;
    currentSec = acurrentSec;
    if (reset == true) {
      resetSleep();
      reset = false;
    }
    // check if it should go to sleep because of time
    if (whenToSleepSec == currentSec && whenToSleepMin == currentMin) {
      //function will provoke a Serial error otherwise!!
      sleepInterval();     // sleep function called here
      currentMin = acurrentMin;
      currentSec = acurrentSec;
    }
  }
  else
  {
    sleepInterval();
  }
}


SleepInterval::SleepInterval(void(*preSleep_)(), short sleepTime_) {
  sleepTime = sleepTime_;
  preSleep = preSleep_;
}

void SleepInterval::resetSleep() {
  whenToSleepSec = currentSec + sleepTime;
  whenToSleepMin = currentMin;
  if (whenToSleepSec > 59) {
    whenToSleepMin = currentMin + (whenToSleepSec - whenToSleepSec % 60) / 60;
    whenToSleepSec -= (whenToSleepSec - whenToSleepSec % 60);
  }
  if (whenToSleepMin > 59) {
    whenToSleepMin -= (whenToSleepMin - whenToSleepMin % 60);
  }
}
// watchdog interrupt
ISR(WDT_vect) {
  wdt_disable();  // disable watchdog
}
void SleepInterval::sleepInterval() {
  disableSleepCycle = true;
  MCUSR = 0;                          // reset various flags
  WDTCSR |= 0b00011000;               // see docs, set WDCE, WDE
  WDTCSR =  0b01000000 | 0b100001;    // set WDIE, and appropriate delay

  wdt_reset();

  //byte adcsra_save = ADCSRA;
  //byte prr_save = PRR;

  // disable ADC
  ///ADCSRA = 0;

  // power reduction register
  // Bit 7 - PRTWI: Power Reduction TWI
  // Bit 6 - PRTIM2: Power Reduction Timer/Counter2
  // Bit 5 - PRTIM0: Power Reduction Timer/Counter0
  // Bit 4 - Res: Reserved bit
  // Bit 3 - PRTIM1: Power Reduction Timer/Counter1
  // Bit 2 - PRSPI: Power Reduction Serial Peripheral Interface
  // Bit 1 - PRUSART0: Power Reduction USART0
  // Bit 0 - PRADC: Power Reduction ADC

  // turn off various modules
  //PRR = 0b11101111;
  
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);   // sleep mode is set here
  attachInterrupt(0, wakeUpNow, HIGH); // use interrupt 0 (pin 2) and run function
  preSleep();
  sleep_mode();            // now goes to Sleep and waits for the interrupt
  detachInterrupt(0);
  
  disableSleepCycle = false;
  if(!digitalRead(2)) {
    disableSleepCycle = true; 
  }
  // stop power reduction
  //ADCSRA = adcsra_save;
  //PRR = prr_save;
  reset = true;
}




