#ifndef Disco_h
#define Disco_h

#include "Arduino.h"
#include "HueClient.h"
#include "HueLight.h"
#include "HueGroup.h"
#include "Sonos.h"
#include "Led.h"
#include <HTTPClient.h>

class Disco {
  public:
    Disco(HueLight& l, HueGroup& g, Sonos& s, Led& led);
    void launch(const char* audioUrl, const char* playerId);
  protected:
    HueLight& _lights;
    HueGroup& _group;
    Sonos& _sonos;
    Led& _led;
};

#endif
