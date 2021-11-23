#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <env.h>
#include <routes/routes.h>
#include <setup.h>

void setup()
{
  Serial.begin(115200);
  connectWifi();
  connectFirebase();
}

void loop()
{
}
