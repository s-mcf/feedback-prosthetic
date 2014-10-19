#include "Ping2.h"

Ping2::Ping2(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  _pinTrig = triggerPin;
  _pinEcho = echoPin;
  _in = 0;
  _cm = 0;
  _duration = -1;
}

Ping2::Ping2(int triggerPin, int echoPin, double in, double cm)
{
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  _pinTrig = triggerPin;
  _pinEcho = echoPin;
  _in = in;
  _cm = cm;
  _duration = -1;
}

void Ping2::fire()
{
  pinMode(_pinTrig, OUTPUT);
  digitalWrite(_pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(_pinTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(_pinTrig, LOW);
  pinMode(_pinEcho, INPUT);
  _duration = pulseIn(_pinEcho, HIGH);
  
}

int Ping2::microseconds()
{
  return _duration;
}

double Ping2::inches()
{
  if(_duration != -1){
    return _duration / (74+_in) / 2;
  }else{
    return -1;
  }
}

double Ping2::centimeters()
{
  if(_duration != -1){
    return _duration / (29+_cm) / 2;
  }else{
    return -1;
  }
}
