#pragma once
#include "Color.h"
#include <Arduino.h>
//#include "Kernel.h"

class Kernel;

//Common framework for apps so that Kernel can call them easily
//More akin to a Rust traits than a real class
class App {
  public:
  App(Kernel* kernel);
  virtual void run_code(double x, double y, bool special, Kernel* kernel)=0;
  virtual String get_name();
};
