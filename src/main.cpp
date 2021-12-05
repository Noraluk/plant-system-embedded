#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <FirebaseESP8266.h>

#include <setup.h>

FirebaseData fbdo;
int pump = 5;
int pumpVal = 0;
int isAsk = false;

void setup()
{
  pinMode(pump, OUTPUT);

  Serial.begin(115200);
  connectWifi();
  connectFirebase();
}

void loop()
{
  Firebase.RTDB.getBool(&fbdo, "/pump/1/is_ask", &isAsk);
  if (isAsk)
  {
    Firebase.RTDB.setBool(&fbdo, "/pump/1/is_ask", false);
    Firebase.RTDB.setBool(&fbdo, "/pump/1/is_working", true);
  }

  Firebase.RTDB.getInt(&fbdo, "/pump/1/is_active", &pumpVal);
  digitalWrite(pump, pumpVal);
}
