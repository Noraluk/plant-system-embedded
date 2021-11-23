#ifndef ROUTES_H
#define ROUTES_H

#include <Arduino.h>
#include <ESP8266WebServer.h>

class Route
{
public:
	Route(int port);
	ESP8266WebServer *server;
	void startServer();
	void initRoutes();

private:
	int _port;
};

#endif