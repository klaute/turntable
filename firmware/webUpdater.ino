/*
  To upload through terminal you can use: curl -F "image=@firmware.bin" esp8266-webupdate.local/update
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>

#include "config.h"

const char* wu_host = "turntable-webupdate";
const char* wu_ssid = "........";
const char* wu_password = "........";

ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;

void setupWebUpdater(void)
{
#ifdef DEBUG
  Serial.println();
  Serial.println("Starting WebUpdater...");
#endif
  /*WiFi.mode(WIFI_AP_STA);
  WiFi.begin(wu_ssid, wu_password);

  while (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    WiFi.begin(wu_ssid, wu_password);
#ifdef DEBUG
    Serial.println("WiFi failed, retrying.");
#endif
  }*/

  MDNS.begin(wu_host);

  httpUpdater.setup(&httpServer);
  httpServer.begin();

  MDNS.addService("http", "tcp", 80);
#ifdef DEBUG
  Serial.println("HTTPUpdateServer ready!");
#endif
}

void doWebUpdater(void)
{
  httpServer.handleClient();
}

