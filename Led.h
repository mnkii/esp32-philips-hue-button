#ifndef Led_h
#define Led_h

#include "Arduino.h"

class Led {
  public:
    Led(const int pin);
    void on();
    void off();
    void toggle();
    bool isOn();

  protected:
    bool _isOn;
    int _pin;
};

#endif
