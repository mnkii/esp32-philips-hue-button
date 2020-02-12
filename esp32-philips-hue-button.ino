/**
 * A one button DIY Philips Hue Remote for an ESP32, tested with DFRobot FireBeetle ESP32
 * 
 * Can be seen in https://youtu.be/HGSPCLT5efM
 * 
 * Works over Wifi by calling the Hue API and has the following functionality:
 *   * Single press toggles the lights on / off
 *   * Double press cycles through scenes
 *   * Long press dims and then brightens
 * 
 * Includes the Sonos hack! When the last scene is selected, will play specified audio file and perform a light show. Your Sonos
 * device must support AudioClip https://developer.sonos.com/reference/control-api/audioclip/
 * 
 * Connect an LED with resistor to 26 and ground
 * Connect a push button to 27 and ground
 * 
 * Modify Config.h for your Wifi, Hue and Sonos setup
 * 
 * Probably worth reading this before trying to get this script up and running: https://developers.meethue.com/develop/get-started-2/
 */
#include "Config.h"
#include <Arduino.h>
#include <PinButton.h>
#include "HueClient.h"
#include "HueGroup.h"
#include "HueLight.h"
#include "Disco.h"
#include "Led.h"
#include <WiFi.h>
#include <WiFiMulti.h>

#define USE_SERIAL Serial

bool buttonHeld = false;
unsigned long scrollDelayCount = 0;
unsigned long ledDelayCount = 0;
int sceneIndex = 0;
bool longClick = false;

PinButton button(BUTTON_PIN);
Led led(LED_PIN);
HueClient conn(HUE_IP, HUE_API_USERNAME);
Sonos sonos(SONOS_ACCESS_TOKEN, SONOS_REFRESH_TOKEN, SONOS_CLIENT_CREDENTIALS);
HueGroup group(conn, HUE_GROUP);
HueLight lights(conn);
Disco disco(lights, group, sonos, led);

void setup()
{
    USE_SERIAL.begin(115200);

    // Connect to wifi
    WiFiMulti wifiMulti;
    for (uint8_t t = 4; t > 0; t--) {
        USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
        USE_SERIAL.flush();
    }
    wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);
    if ((wifiMulti.run() != WL_CONNECTED)) {
        USE_SERIAL.println("Unable to connect");
    }
}

void loop()
{
    button.update();

    if (button.isClick()) {
        led.on();
    }

    if (button.isSingleClick()) {
        group.toggle();
    }

    if (button.isDoubleClick()) {
        if (sceneIndex >= (sizeof scenes / sizeof scenes[0]) + 1) {
            sceneIndex = 0;
        }
        if (sceneIndex < (sizeof scenes / sizeof scenes[0])) {
            group.setScene(scenes[sceneIndex]);
        }
        else {
            disco.launch(AUDIO_URL, SONOS_ID);
        }
        sceneIndex++;
    }

    if (button.isLongClick()) {
        scrollDelayCount = 0;
        group.scrollBrightnessStart();
        buttonHeld = true;
        longClick = true;
    }

    if (button.isReleased()) {
        buttonHeld = false;
        if (longClick) {
            led.off();
            ledDelayCount = 0;
            longClick = false;
        }
    }

    if (buttonHeld) {
        scrollDelayCount++;
        if (scrollDelayCount > 200000) {
            group.scrollBrightnessTick();
            scrollDelayCount = 0;
        }
    }

    // Keeps LED on for a short amount of time if button is pressed, but not long pressed
    if (led.isOn() && !longClick) {
        ledDelayCount++;
        if (ledDelayCount > 1500000) {
            led.off();
            ledDelayCount = 0;
            longClick = false;
        }
    }
}
