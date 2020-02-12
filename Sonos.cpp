#include "Arduino.h"
#include "Sonos.h"
#include <HTTPClient.h>

#define USE_SERIAL Serial

Sonos::Sonos(String accessToken, String refreshToken, const char* clientCredentials)
    : _accessToken(accessToken)
    , _refreshToken(refreshToken)
    , _clientCredentials(clientCredentials)
{
    HTTPClient _http;
}

void Sonos::playAudio(const char* audioUrl, const char* playerId)
{
    if (Sonos::_playAudio(audioUrl, playerId) == 403) {
        Sonos::_refreshAccessToken();
        Sonos::_playAudio(audioUrl, playerId);
    }
}

int Sonos::_playAudio(const char* audioUrl, const char* playerId)
{
    HTTPClient http;
    USE_SERIAL.println("playAudio");
    char sonosUri[100];
    sprintf(sonosUri, "https://api.ws.sonos.com/control/api/v1/players/%s/audioClip", playerId);
    http.begin(sonosUri);
    http.addHeader("Content-Type", "application/json");

    http.addHeader("Authorization", "Bearer " + _accessToken);

    char payload[500];
    sprintf(payload, "{\"name\": \"Sound clip\", \"appId\": \"esp32\",\"streamUrl\": \"%s\",\"clipType\": \"CUSTOM\"}", audioUrl);
    int httpCode = http.POST(payload);
    USE_SERIAL.printf("[HTTP] Sonos audioClip response code... %d\n", httpCode);
    http.end();
    return httpCode;
}

void Sonos::_refreshAccessToken()
{
    HTTPClient http;
    http.begin("https://api.sonos.com/login/v3/oauth/access");
    http.addHeader("Content-Type", "application/x-www-form-urlencoded;charset=utf-8");

    char authHeader[200];
    sprintf(authHeader, "Basic %s", _clientCredentials);
    http.addHeader("Authorization", authHeader);

    String payload = "grant_type=refresh_token&refresh_token=" + _refreshToken;
    int httpCode = http.POST(payload);
    if (httpCode != 200) {
        USE_SERIAL.printf("Unexpected sesponse code refreshing access token: %d", httpCode);
        return;
    }
    USE_SERIAL.println("----------------------");
    USE_SERIAL.printf("Current access token %s", _accessToken);
    USE_SERIAL.printf("Current refresh token %s", _refreshToken);
    USE_SERIAL.println("requesting");
    String response = http.getString();
    _accessToken = Sonos::_extractJsonValue("access_token", response);
    _refreshToken = Sonos::_extractJsonValue("refresh_token", response);
    USE_SERIAL.printf("New Refresh token %s", _accessToken);
    USE_SERIAL.printf("New refresh token %s", _refreshToken);
    USE_SERIAL.print(response);
    http.end();
}

String Sonos::_extractJsonValue(String key, String body)
{
    int startPos = body.indexOf(key) + key.length() + 3;
    int endPos = body.indexOf("\"", startPos);
    return body.substring(startPos, endPos);
}
