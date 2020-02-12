# ESP32 Philips Hue DIY Light Switch

A one button DIY Philips Hue Remote for an ESP32, tested with DFRobot FireBeetle ESP32.

Can be seen in [this video](https://youtu.be/HGSPCLT5efM)

Works over Wifi by calling the Hue API and has the following functionality:
 * Single press toggles the lights on / off
 * Double press cycles through scenes
 * Long press dims and then brightens

Includes a small Sonos Disco as per the video! When the last scene is selected, will play specified audio file and
perform a light show.

Your Sonos device must support [AudioClip](https://developer.sonos.com/reference/control-api/audioclip/) 

## Circuit

Connect an LED with resistor to 26 and ground
Connect a push button to 27 and ground

## Setup

Modify Config.h for your Wifi, Hue and Sonos setup

Probably worth reading the [Hue Getting Started Guide](https://developers.meethue.com/develop/get-started-2/) before trying to get this script up and running

To get the disco mode going, you will want to modify Disco.cpp to create your own light show.