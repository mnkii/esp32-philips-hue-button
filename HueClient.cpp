#include "Arduino.h"
#include "HueClient.h"
#include <HTTPClient.h>

#define USE_SERIAL Serial

HueClient::HueClient(const char* ip, const char* user)
    : _ip(ip)
    , _user(user)
{
    HTTPClient _http;
}

String HueClient::request(const char* httpMethod, const char* endpoint, const char* payload)
{
    char url[200];
    sprintf(url, "http://%s/api/%s%s", _ip, _user, endpoint);
    _http.begin(url);

    int httpCode;
    if (httpMethod == "GET") {
        httpCode = _http.GET();
    }
    else if (httpMethod == "PUT") {
        httpCode = _http.PUT(payload);
    }
    else if (httpMethod == "POST") {
        httpCode = _http.POST(payload);
    }
    else {
        USE_SERIAL.printf("Method not implemented: ", httpMethod);
        throw "HTTP method not implemented";
    }

    if (httpCode > 0) {
        if (httpCode == HTTP_CODE_OK) {
            String payload = _http.getString();
            return payload;
        }
    }
    else {
        USE_SERIAL.printf("[HTTP] PUT... failed, error: %s\n", _http.errorToString(httpCode).c_str());
    }

    _http.end();
}
