#ifndef Sonos_h
#define Sonos_h

#include "Arduino.h"
#include <HTTPClient.h>

class Sonos
{
  public:
    Sonos(String accessToken, String refreshToken, const char * clientCredentials);
    void playAudio(const char *audioUrl, const char *playerId);
  protected:
    int _playAudio(const char *audioUrl, const char *playerId);
    void _refreshAccessToken();
    String _extractJsonValue(String key, String body);
    String _accessToken;
    String _refreshToken;
    const char * _clientCredentials;
};

#endif
