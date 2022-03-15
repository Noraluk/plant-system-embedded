#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <FirebaseESP8266.h>

#include <setup.h>

FirebaseData fbdo;
int pump = 5;
int pumpVal = 0;
bool isAsk = false;

unsigned long dataMillis = 0;

void setup()
{
  pinMode(pump, OUTPUT);

  Serial.begin(115200);
  connectWifi();
  connectFirebase();
}

void loop()
{
  if (Firebase.ready() && millis() - dataMillis > 5000)
  {
    dataMillis = millis();
    Firebase.getBool(fbdo, "pump/1/is_ask", &isAsk);
    if (isAsk)
    {
      Firebase.setBool(fbdo, "/pump/1/is_ask", false);
      Firebase.setBool(fbdo, "/pump/1/is_working", true);
    }

    Serial.printf("Get is active... %s\n", Firebase.getInt(fbdo, "/pump/1/is_active", &pumpVal) ? "ok" : fbdo.errorReason().c_str());

    digitalWrite(pump, pumpVal);
  }
}
