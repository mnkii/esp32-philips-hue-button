/**
 * See README.md for details
 *
 * Modify Config.h for your Wifi and Hue setup
 */
#include "Config.h"
#include <Arduino.h>
#include <PinButton.h>
#include "HueClient.h"
#include "HueGroup.h"
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
HueGroup group(conn, HUE_GROUP);

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
        if (sceneIndex >= (sizeof scenes / sizeof scenes[0])) {
            sceneIndex = 0;
        }

        group.setScene(scenes[sceneIndex]);

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
