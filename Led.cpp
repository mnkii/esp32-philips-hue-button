#include "Arduino.h"
#include "Led.h"

#define USE_SERIAL Serial

Led::Led(const int pin)
    : _pin(pin)
    , _isOn(0)
{
    pinMode(_pin, OUTPUT);
}

void Led::on()
{
    digitalWrite(_pin, 1);
    _isOn = true;
}

void Led::off()
{
    digitalWrite(_pin, 0);
    _isOn = false;
}

void Led::toggle()
{
    digitalWrite(_pin, !_isOn);
    _isOn = !_isOn;
}

bool Led::isOn()
{
    return _isOn;
}
