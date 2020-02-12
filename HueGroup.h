#ifndef HueGroup_h
#define HueGroup_h

#include "Arduino.h"
#include "HueClient.h"
#include <HTTPClient.h>

class HueGroup {
  public:
    HueGroup(HueClient& c, int group);
    void toggle();
    void scrollBrightnessStart();
    void scrollBrightnessTick();
    void on();
    void off();
    void setScene(char* scene);

  private:
    HueClient& _conn;
    int _group;
    int _brightness;
    boolean _brightnessAscending;
};

#endif
