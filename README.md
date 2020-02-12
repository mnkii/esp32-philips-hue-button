# ESP32 Philips Hue DIY Light Switch With Sonos Integration

A one button DIY Philips Hue Remote for an ESP32, tested with DFRobot FireBeetle ESP32.

This branch contains the code as per [this video](https://youtu.be/HGSPCLT5efM)  When the last scene is selected, will play specified audio file and perform a light show.

Works over Wifi by calling the Hue API and has the following functionality:
 * Single press toggles the lights on / off
 * Double press cycles through scenes
 * Long press dims and then brightens

Includes a small Sonos Disco as per the video!

Your Sonos device must support [AudioClip](https://developer.sonos.com/reference/control-api/audioclip/) 

To help generate Sonos credentials, [this](https://github.com/mnkii/sonos-token) could be useful.

## Circuit

Connect an LED with resistor to 26 and ground
Connect a push button to 27 and ground

## Setup

Modify Config.h for your Wifi, Hue and Sonos setup

It is probably worth reading the [Hue Getting Started Guide](https://developers.meethue.com/develop/get-started-2/) before trying to get this script up and running

To get the disco mode going, you will want to modify Disco.cpp to create your own light show.
