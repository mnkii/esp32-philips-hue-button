#include "Arduino.h"
#include "HueLight.h"

#define USE_SERIAL Serial

HueLight::HueLight(HueClient& c)
    : _conn(c)
{
}

void HueLight::off(char* light)
{
    HueLight::_call(light, "{\"on\":false, \"transitiontime\": 0}");
}

void HueLight::yellow(char* light)
{
    HueLight::_call(light, "{\"on\":true, \"sat\":254, \"bri\":254, \"hue\": 10000, \"transitiontime\": 0}");
}

void HueLight::red(char* light)
{
    HueLight::_call(light, "{\"on\":true, \"sat\":254, \"bri\":254, \"hue\": 500, \"transitiontime\": 0}");
}

void HueLight::blue(char* light)
{
    HueLight::_call(light, "{\"on\":true, \"sat\":254, \"bri\":254, \"hue\": 45000, \"transitiontime\": 0}");
}

void HueLight::green(char* light)
{
    HueLight::_call(light, "{\"on\":true, \"sat\":254, \"bri\":254, \"hue\": 25000, \"transitiontime\": 0}");
}

void HueLight::purple(char* light)
{
    HueLight::_call(light, "{\"on\":true, \"sat\":254, \"bri\":254, \"hue\": 55000, \"transitiontime\": 0}");
}

void HueLight::orange(char* light)
{
    HueLight::_call(light, "{\"on\":true, \"sat\":254, \"bri\":254, \"hue\": 6000, \"transitiontime\": 0}");
}

void HueLight::white(char* light)
{
    HueLight::_call(light, "{\"on\":true, \"sat\":0, \"bri\":254, \"hue\": 0, \"transitiontime\": 0}");
}

void HueLight::_call(char* light, char* body)
{
    char endpoint[100];
    sprintf(endpoint, "/lights/%s/state", light);
    _conn.request("PUT", endpoint, body);
}
