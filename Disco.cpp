#include "Disco.h"
#include "Arduino.h"
#include <HTTPClient.h>

#define USE_SERIAL Serial

Disco::Disco(HueLight& l, HueGroup& g, Sonos& s, Led& led)
    : _lights(l)
    , _group(g)
    , _sonos(s)
    , _led(led)
{
}

void Disco::launch(const char* audioUrl, const char* playerId)
{
    int xxShortDelay = 100;
    int xShortDelay = 150;
    int shortDelay = 180;
    int mediumDelay = 300;
    int longDelay = 500;

    char* over1 = "20";
    char* over2 = "23";
    char* over3 = "19";
    char* under1 = "9";
    char* under2 = "10";
    char* under3 = "8";

    _group.off();
    _sonos.playAudio(audioUrl, playerId);

    // colours changing - columns
    _lights.green(over1);
    _lights.green(under1);
    delay(shortDelay);
    _group.off();
    delay(shortDelay);
    _led.toggle();
    _lights.blue(over2);
    _lights.blue(under2);
    delay(shortDelay);
    _group.off();
    delay(shortDelay);
    _led.toggle();
    _lights.orange(over3);
    _lights.orange(under3);
    delay(shortDelay);
    _group.off();
    delay(shortDelay);
    _led.toggle();
    _lights.purple(under2);
    _lights.purple(under2);
    delay(shortDelay);
    _group.off();
    delay(shortDelay);
    _led.toggle();
    _lights.red(over1);
    _lights.red(over1);
    delay(shortDelay);

    // Colours changing - rows
    _lights.green(over1);
    _lights.green(over2);
    _lights.green(over3);
    _led.toggle();
    delay(shortDelay);
    _group.off();
    _led.toggle();
    delay(shortDelay);
    _lights.blue(under1);
    _lights.blue(under2);
    _lights.blue(under3);
    _led.toggle();
    delay(shortDelay);
    _group.off();
    _led.toggle();
    delay(shortDelay);
    _lights.orange(over1);
    _lights.orange(over2);
    _lights.orange(over3);
    _led.toggle();
    delay(shortDelay);
    _group.off();
    _led.toggle();
    delay(shortDelay);
    _lights.purple(under1);
    _lights.purple(under2);
    _lights.purple(under3);
    _led.toggle();
    delay(shortDelay);
    _group.off();
    _led.toggle();
    delay(shortDelay);
    _lights.red(over1);
    _lights.red(over2);
    _lights.red(over3);
    _led.toggle();
    delay(shortDelay);
    _group.off();
    delay(shortDelay);
    _lights.yellow(under1);
    _lights.yellow(under2);
    _lights.yellow(under3);
    _led.toggle();
    delay(shortDelay);
    _group.off();

    // Colours changing - columns, no off
    _lights.green(over1);
    _lights.green(under1);
    _led.toggle();
    delay(shortDelay);
    _lights.blue(over2);
    _lights.blue(under2);
    _led.toggle();
    delay(shortDelay);
    _lights.orange(over3);
    _lights.orange(under3);
    _led.toggle();
    delay(shortDelay);
    _lights.purple(under2);
    _lights.purple(under2);
    _led.toggle();
    delay(shortDelay);
    _lights.red(over1);
    _lights.red(over1);
    _led.toggle();
    delay(shortDelay);

    _lights.blue(over1);
    _lights.blue(under1);
    _led.toggle();
    delay(shortDelay);
    _lights.green(over2);
    _lights.green(under2);
    _led.toggle();
    delay(shortDelay);
    _lights.purple(over3);
    _lights.purple(under3);
    _led.toggle();
    delay(shortDelay);
    _lights.red(under2);
    _lights.red(under2);
    _led.toggle();
    delay(shortDelay);
    _lights.yellow(over1);
    _lights.yellow(over1);
    _led.toggle();
    delay(shortDelay);

    _lights.yellow(over1);
    _lights.yellow(under1);
    _led.toggle();
    delay(shortDelay);
    _lights.red(over2);
    _lights.red(under2);
    _led.toggle();
    delay(shortDelay);
    _lights.orange(over3);
    _lights.orange(under3);
    _led.toggle();
    delay(shortDelay);
    _lights.purple(under2);
    _lights.purple(under2);
    _led.toggle();
    delay(shortDelay);
    _lights.green(over1);
    _lights.green(over1);
    _led.toggle();
    delay(shortDelay);

    _lights.blue(over1);
    _lights.blue(under1);
    _led.toggle();
    delay(shortDelay);
    _lights.green(over2);
    _lights.green(under2);
    _led.toggle();
    delay(shortDelay);
    _led.toggle();
    _group.off();
    _led.off();
    delay(shortDelay);
}
