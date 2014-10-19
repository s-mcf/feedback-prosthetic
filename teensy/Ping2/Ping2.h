#ifndef Ping2_h
#define Ping2_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Ping2
{
  public:
    Ping2(int triggerPin, int echoPin);
    Ping2(int triggerPin, int echoPin, double in, double cm);
    void fire();
    int microseconds();
    double inches();
    double centimeters();
  private:
    int _pinTrig;
    int _pinEcho;
    double _in;
    double _cm;
    long _duration;
};

#endif
