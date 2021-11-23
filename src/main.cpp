#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <FirebaseESP8266.h>

#include <setup.h>

FirebaseData fbdo;
int led = 5;
int ledValue = 0;

void setup()
{
  pinMode(btn, INPUT);
  pinMode(led, OUTPUT);

  Serial.begin(115200);
  connectWifi();
  connectFirebase();
}

void loop()
{
  Firebase.RTDB.getInt(&fbdo, "/led", &ledValue);
  digitalWrite(led, ledValue);
}
