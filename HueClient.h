#ifndef HueClient_h
#define HueClient_h

#include "Arduino.h"
#include <HTTPClient.h>

class HueClient {
public:
    HueClient(const char* ip, const char* user);
    String request(const char* method, const char* endpoint, const char* payload = "");

protected:
    const char* _ip;
    const char* _user;
    HTTPClient _http;
};

#endif
