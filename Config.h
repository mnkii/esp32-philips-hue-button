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

// Sonos Config
#define AUDIO_URL "" // URL of audio file to play
#define SONOS_CLIENT_CREDENTIALS "" // base64 encoded client_id:client_secret
#define SONOS_ACCESS_TOKEN "" // These are tricky to generate - you will have to create your own sonos integration and then use the
#define SONOS_REFRESH_TOKEN "" // API to generate the access and refresh token https://developer.sonos.com/reference/authorization-api/
#define SONOS_ID "" // playerId - must be one which supports audioclip https://developer.sonos.com/reference/control-api/audioclip/
