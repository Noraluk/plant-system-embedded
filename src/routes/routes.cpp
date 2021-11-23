#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include <uri/UriBraces.h>

#include <routes/routes.h>

Route::Route(int port)
{
	_port = port;
	server = new ESP8266WebServer(port);
}

void Route::startServer()
{
	if (MDNS.begin("esp8266"))
	{
		Serial.println("MDNS responder started");
	}

	initRoutes();
	server->begin();
	Serial.println("listening server on port : " + String(_port));
}

void Route::initRoutes()
{
	server->on("/inline", [&]()
		   { server->send(200, "text/plain", "this works as well"); });
}