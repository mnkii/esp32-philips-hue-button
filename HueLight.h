#ifndef HueLight_h
#define HueLight_h

#include "Arduino.h"
#include "HueClient.h"
#include <HTTPClient.h>

class HueLight {
  public:
    HueLight(HueClient& c);
    void off(char* light);
    void yellow(char* light);
    void red(char* light);
    void blue(char* light);
    void green(char* light);
    void purple(char* light);
    void orange(char* light);
    void white(char* light);

  private:
    HueClient& _conn;
    void _call(char* light, char* body);
};

#endif
