
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

uint8_t  mx_bm       = 0x00;
uint16_t delay_ms_u8 = 100;
boolean  dir_b       = true;
boolean  enabled_b   = true;

WiFiManager wifiManager;

void setup() { 
  #ifdef DEBUG
    Serial.begin(115200);
  #endif

  // Pin settings
  pinMode(STATUS_LED_PIN, OUTPUT);
  pinMode(MX1_PIN, OUTPUT);
  pinMode(MX2_PIN, OUTPUT);
  pinMode(MX3_PIN, OUTPUT);
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

  digitalWrite(STATUS_LED_PIN, LOW);
}

void loop() {
  
  // TODO process the webserver settings (parallalize it)

  digitalWrite(STATUS_LED_PIN, LOW);

  #ifdef DEBUG
    //Serial.println("State: " + String() + " hPa");
  #endif

  digitalWrite(MX1_PIN,  ((mx_bm & 0x01)       ? HIGH : LOW));
  digitalWrite(MX2_PIN, (((mx_bm & 0x01) >> 1) ? HIGH : LOW));
  digitalWrite(MX3_PIN, (((mx_bm & 0x02) >> 2) ? HIGH : LOW));

  digitalWrite(DIR_PIN, (dir_b == true ? HIGH : LOW));

  if (enabled_b = true)
  {
    digitalWrite(STEP_PIN, HIGH);
    delay(delay_ms_u8);
    digitalWrite(STEP_PIN, LOW);
  }
}
