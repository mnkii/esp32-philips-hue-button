# ESP32 Philips Hue DIY Light Switch

A one button DIY Philips Hue Remote for an ESP32, tested with DFRobot FireBeetle ESP32.

There is also a [fork with the Sonos integration](https://github.com/mnkii/esp32-philips-hue-button-with-sonos).

This code, with the Sonos integration can be seen in [this video](https://youtu.be/HGSPCLT5efM)

Works over Wifi by calling the Hue API and has the following functionality:

 * Single press toggles the lights on / off
 * Double press cycles through scenes
 * Long press dims and then brightens

## Circuit

Connect an LED with resistor to 26 and ground

Connect a push button to 27 and ground

## Setup

Modify Config.h for your Wifi and Hue setup.

It is worth reading the [Hue Getting Started Guide](https://developers.meethue.com/develop/get-started-2/) before trying
to get this script up and running
