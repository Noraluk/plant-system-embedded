#ifndef ENV_H
#define ENV_H

#include "Arduino.h"

// Create env header and copy this to the target and remove EX_
extern String EX_WIFI_SSID;
extern String EX_WIFI_PASSWORD;
extern String EX_API_KEY;
extern String EX_DATABASE_URL;
extern String EX_USER_EMAIL;
extern String EX_USER_PASSWORD;
extern String EX_DATABASE_SECRET;

#endif