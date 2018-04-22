/*
  To upload through terminal you can use: curl -F "image=@firmware.bin" esp8266-webupdate.local/update
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>

#include "config.h"

ESP8266WebServer httpServer(8080);
ESP8266HTTPUpdateServer httpUpdater;

void setupWebUpdater(void)
{
#ifdef DEBUG
  Serial.println();
  Serial.println("Starting WebUpdater...");
#endif

  httpUpdater.setup(&httpServer);
  httpServer.begin();

#ifdef DEBUG
  Serial.println("HTTPUpdateServer ready!");
#endif
}

void doWebUpdater(void)
{
  httpServer.handleClient();
}

