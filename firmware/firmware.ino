
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

#include "config.h"

/**
 * Whishlist:
 * - Webserver for turntable control
 * - OTA firmware update
 * 
 */

uint8_t  ms_bm        = 0x00;
uint16_t delay_ms_u16 = 100;
boolean  dir_b        = true;
boolean  enabled_b    = true;

WiFiManager wifiManager;
WiFiServer server(80); //Initialize the server on Port 80

void setup()
{

#ifdef DEBUG
  Serial.begin(115200);
#endif

  digitalWrite(STATUS_LED_PIN, HIGH);
  
  // Pin settings
  pinMode(STATUS_LED_PIN, OUTPUT);
  pinMode(MS1_PIN, OUTPUT);
  pinMode(MS2_PIN, OUTPUT);
  pinMode(MS3_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  // Establish WiFi connection
  String wifiName = "turntable-" + String(ESP.getChipId());
  wifiManager.setMinimumSignalQuality(15);
  if (!wifiManager.autoConnect(wifiName.c_str(), "DEADBEEF")) {
    #ifdef DEBUG
      Serial.println("WiFi connection failed, we reboot ...");
    #endif
      ESP.reset();
      delay(1000);
  }
#ifdef DEBUG
  Serial.println("Connected!");
#endif

  delay(100);

  server.begin(); // Start the HTTP Server

  digitalWrite(STATUS_LED_PIN, LOW);
}

void loop()
{
  
  WiFiClient client = server.available();
  if (client)
  { 
    // TODO process the webserver settings (parallalize it)
    String request = client.readStringUntil('\r');
    if (request.indexOf("/EN") != -1)
    {
      Serial.println("Enable rotation");
      enabled_b = true;
    } else if (request.indexOf("/DIS") != -1)
    {
      Serial.println("Disable rotation");
      enabled_b = false;
    }
  } 

  digitalWrite(STATUS_LED_PIN, LOW);

#ifdef DEBUG
  static uint16_t time_ms_u16 = 0;
  if (time_ms_u16 > 2000)
  {
    time_ms_u16 = 0;
    Serial.println("Status: " + String(enabled_b) + " " + String(ms_bm) + " " + String(dir_b) + " " + String(delay_ms_u16));
  }
  time_ms_u16 += delay_ms_u16;
#endif

  digitalWrite(MS1_PIN,  ((ms_bm & 0x01)       ? HIGH : LOW));
  digitalWrite(MS2_PIN, (((ms_bm & 0x01) >> 1) ? HIGH : LOW));
  digitalWrite(MS3_PIN, (((ms_bm & 0x02) >> 2) ? HIGH : LOW));

  digitalWrite(DIR_PIN, (dir_b == true ? HIGH : LOW));

  if (enabled_b == true)
  {
    digitalWrite(STEP_PIN, HIGH);
    delay(delay_ms_u16);
    digitalWrite(STEP_PIN, LOW);
  }
}


