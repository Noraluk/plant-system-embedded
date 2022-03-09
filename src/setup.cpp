#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <FirebaseESP8266.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

#include <env.h>
#include <setup.h>

FirebaseAuth auth;
FirebaseConfig config;

void connectWifi()
{
	WiFi.mode(WIFI_STA);
	WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

	Serial.println("");

	// Wait for connection
	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}

	Serial.println("");
	Serial.print("Connected to ");
	Serial.println(WIFI_SSID);
	Serial.print("IP address: ");
	Serial.println(WiFi.localIP());
}

void connectFirebase()
{
	config.api_key = API_KEY;
	config.database_url = DATABASE_URL;

	Firebase.reconnectWiFi(true);

	auth.user.email = USER_EMAIL;
	auth.user.password = USER_PASSWORD;

	config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h
	config.max_token_generation_retry = 5;

	Firebase.begin(&config, &auth);

	Serial.println("connecting to firebase");
	while (Firebase.ready() == false)
	{
		Serial.print(".");
	}
	Serial.println("connected to firebase");
}