// GPIO config
#define BUTTON_PIN 27 // The pin the button is connected to
#define LED_PIN 26 // The pin the LED is connected to

// Wifi Config
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

// Hue Config
#define HUE_IP "" // IP of your hue bridge (you might want to give it a static IP on your router), see https://www.meethue.com/api/nupnp
#define HUE_API_USERNAME "" // See https://developers.meethue.com/develop/get-started-2/
#define HUE_GROUP 3 // Numeric id of the group of lights you want to control, call hue api /api/{ username }/groups for this
char scenes[3][16] = { // 15 digit ids of the scenes you want the switch to iterate through. Call hue api /api/{ username }/scenes for these
    "", // Choose only scenes available for your chosen group
    "",
    ""
};
