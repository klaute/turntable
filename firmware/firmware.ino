
//*************************************************************************//

#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

#include "config.h"

//*************************************************************************//

uint16_t delay_between_us_u16 =  1;
uint16_t delay_after_ms_u16   = 40;

//*************************************************************************//

uint8_t  ms_bm_u8           = 0x00; // ms1-3 bits
boolean  dir_b              = true;
boolean  enabled_b          = true;

String localIP = "127.0.0.1";

//*************************************************************************//

String html_default_header_s = "HTTP/1.1 200 OK\nContent-Type: text/html\n"
"Access-Control-Allow-Origin: *\n"
"Access-Control-Allow-Methods: *\n"
"Connection: close\n\n";
String html_status_start_s = "<html><head></head><body>\n";
String html_status_end_s  = "</body></html>\n";
String html_status_ok_s = html_status_start_s + "OK" + html_status_end_s;

//*************************************************************************//

WiFiManager wifiManager;
WiFiServer server(80); // Initialize the server on Port 80

//*************************************************************************//

void setup()
{

#ifdef DEBUG
  Serial.begin(115200);
#endif

  digitalWrite(STATUS_LED_PIN, HIGH);
  
  // Pin settings
  pinMode(STATUS_LED_PIN, OUTPUT);
  pinMode(MS1_PIN,  OUTPUT);
  pinMode(MS2_PIN,  OUTPUT);
  pinMode(MS3_PIN,  OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN,  OUTPUT);

  // Establish WiFi connection
  String wifiName = "turntable-" + String(ESP.getChipId());
  wifiManager.setMinimumSignalQuality(15);
  if (!wifiManager.autoConnect(wifiName.c_str(), "DEADBEEF"))
  {
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

  // only do once after the first flashing of the mcu
  /*
  setTTEEPDefaultCfg(0);
  setTTEEPDefaultCfg(1);
  setTTEEPDefaultCfg(2);
  saveTTEEPConfig();
  */

  loadTTEEPConfig();

  tt_eep_configData_t tmp_eep_config = getTTEEPConfig(0);

  enabled_b            = tmp_eep_config.enabled_on_start_b;
  dir_b                = tmp_eep_config.dir_in_start_b;
  delay_after_ms_u16   = tmp_eep_config.delay_after_ms_u16;
  delay_between_us_u16 = tmp_eep_config.delay_between_us_u16;
  ms_bm_u8             = tmp_eep_config.ms_bm_u8;

  server.begin(); // Start the HTTP Server

  localIP = WiFi.localIP().toString();

  // set the new settings
  digitalWrite(MS1_PIN, (ms_bm_u8 & 0x01) ? HIGH : LOW);
  digitalWrite(MS2_PIN, (ms_bm_u8 & 0x02) ? HIGH : LOW);
  digitalWrite(MS3_PIN, (ms_bm_u8 & 0x04) ? HIGH : LOW);

  digitalWrite(DIR_PIN, (dir_b == true ? HIGH : LOW));

  digitalWrite(STATUS_LED_PIN, LOW);
}

//*************************************************************************//

void doWebserver()
{
  WiFiClient client = server.available();
  if (client)
  {
    String request = client.readStringUntil('\r');
    boolean dir_old_b = dir_b;
    uint8_t ms_old_bm_u8 = ms_bm_u8;

    if (request.indexOf("/EN") != -1)
    {
#ifdef DEBUG
      Serial.println("Rotation enabled");
#endif
      enabled_b = true;
      client.print(html_default_header_s);
      client.print(html_status_ok_s);

    } else if (request.indexOf("/DIS") != -1)
    {
#ifdef DEBUG
      Serial.println("Rotation disabled");
#endif
      enabled_b = false;
      client.print(html_default_header_s);
      client.print(html_status_ok_s);

    } else if (request.indexOf("/INC_DLY_BT") != -1)
    {
#ifdef DEBUG
      Serial.println("Increase delay between");
#endif
      if (delay_between_us_u16 <= 199)
        delay_between_us_u16 += 1;
      client.print(html_default_header_s);
      client.print(html_status_ok_s);

    } else if (request.indexOf("/DEC_DLY_BT") != -1)
    {
#ifdef DEBUG
      Serial.println("Decrease delay between");
#endif
      if (delay_between_us_u16 >= 2)
        delay_between_us_u16 -= 1;
      client.print(html_default_header_s);
      client.print(html_status_ok_s);

    } else if (request.indexOf("/INC_DLY_AF") != -1)
    {
#ifdef DEBUG
      Serial.println("Increase delay after");
#endif
      if (delay_after_ms_u16 <= 995)
        delay_after_ms_u16 += 5;
      client.print(html_default_header_s);
      client.print(html_status_ok_s);

    } else if (request.indexOf("/DEC_DLY_AF") != -1)
    {
#ifdef DEBUG
      Serial.println("Decrease delay after");
#endif
      if (delay_after_ms_u16 >= 10)
        delay_after_ms_u16 -= 5;
      client.print(html_default_header_s);
      client.print(html_status_ok_s);

    } else if (request.indexOf("/DIR_H") != -1)
    {
#ifdef DEBUG
      Serial.println("Direction left");
#endif
      dir_b = true;
      client.print(html_default_header_s);
      client.print(html_status_ok_s);

    } else if (request.indexOf("/DIR_L") != -1)
    {
#ifdef DEBUG
      Serial.println("Direction right");
#endif
      dir_b = false;
      client.print(html_default_header_s);
      client.print(html_status_ok_s);

    } else if (request.indexOf("/MS_BM_") != -1)
    {
      uint16_t start = request.indexOf("/MS_BM_") + 7;
      String tstr = request.substring(start, start+3);
      ms_bm_u8  = tstr.substring(0,1).toInt();
      ms_bm_u8 += tstr.substring(1,2).toInt() << 1;
      ms_bm_u8 += tstr.substring(2,3).toInt() << 2;
      client.print(html_default_header_s);
      client.print(html_status_ok_s);

#ifdef DEBUG
      Serial.println("MS bitmask " + tstr + " " + String(ms_bm_u8));
#endif
    } else if (request.indexOf("/STAT") != -1)
    {
#ifdef DEBUG
      Serial.println("Get status");
#endif
      // TODO return the status
      client.print(html_default_header_s);
      //client.print(html_status_start_s);
      client.println(String(enabled_b)            + ";" +
                     String(ms_bm_u8)             + ";" +
                     String(dir_b)                + ";" +
                     String(delay_between_us_u16) + ";" +
                     String(delay_after_ms_u16));
      //client.println(html_status_end_s);

    } else if (request.indexOf("/SAVE_") != -1)
    {
      uint16_t start = request.indexOf("/SAVE_") + 6;
      String tstr = request.substring(start, start + 1);
      uint8_t idx_u8 = tstr.substring(0,1).toInt();
      if (idx_u8 <= TT_EEP_CFG_IDX_MAX)
      {
        client.print(html_default_header_s);
        client.print(html_status_ok_s);

        tt_eep_configData_t cfg;
        cfg.enabled_on_start_b   = enabled_b;
        cfg.dir_in_start_b       = dir_b;
        cfg.delay_after_ms_u16   = delay_after_ms_u16;
        cfg.delay_between_us_u16 = delay_between_us_u16;
        cfg.ms_bm_u8             = ms_bm_u8;

        setTTEEPConfig(cfg, idx_u8);
        saveTTEEPConfig();
        
#ifdef DEBUG
        Serial.println("Saving EEPROM config with index " + String(idx_u8));
      } else {
        Serial.println("Invalid EEPROM index " + String(idx_u8));
#endif
      }
    } else if (request.indexOf("/LOAD_") != -1)
    {
      uint16_t start = request.indexOf("/LOAD_") + 6;
      String tstr = request.substring(start, start + 1);
      uint8_t idx_u8 = tstr.substring(0,1).toInt();
      if (idx_u8 <= TT_EEP_CFG_IDX_MAX)
      {
        client.print(html_default_header_s);
        client.print(html_status_ok_s);

        loadTTEEPConfig();
        tt_eep_configData_t cfg = getTTEEPConfig(idx_u8);
        enabled_b            = cfg.enabled_on_start_b;
        dir_b                = cfg.dir_in_start_b;
        delay_after_ms_u16   = cfg.delay_after_ms_u16;
        delay_between_us_u16 = cfg.delay_between_us_u16;
        ms_bm_u8             = cfg.ms_bm_u8;
        
#ifdef DEBUG
        Serial.println("Loading EEPROM config with index " + String(idx_u8));
      } else {
        Serial.println("Invalid EEPROM index " + String(idx_u8));
#endif
      }
    } else {
      client.print(html_default_header_s);
      printHTMLCtrlPanel(client, localIP);
    }

    // set the new settings
    if (ms_old_bm_u8 != ms_bm_u8)
    {
      digitalWrite(MS1_PIN, (ms_bm_u8 & 0x01) ? HIGH : LOW);
      digitalWrite(MS2_PIN, (ms_bm_u8 & 0x02) ? HIGH : LOW);
      digitalWrite(MS3_PIN, (ms_bm_u8 & 0x04) ? HIGH : LOW);
    }

    if (dir_old_b != dir_b)
      digitalWrite(DIR_PIN, (dir_b == true ? HIGH : LOW));
  }
}

void loop()
{
  doWebserver();

  //Serial.println(">>"+);

#ifdef DEBUG
  static uint16_t time_ms_u16 = 0;
  if (time_ms_u16 >= STATUS_OUTPUT_DELAY_MS)
  {
    time_ms_u16 = 0;
    Serial.println("Status: " + String(enabled_b) + " " + String(ms_bm_u8)
                   + " " + String(dir_b) + " " + String(delay_between_us_u16)
                   + " " + String(delay_after_ms_u16));
  }
  time_ms_u16 += delay_after_ms_u16;
#endif

  if (enabled_b == true)
  {
    digitalWrite(STEP_PIN, HIGH);

    delayMicroseconds(delay_between_us_u16);

    digitalWrite(STEP_PIN, LOW);
#ifdef DEBUG
    //Serial.print(".");
#endif
  }

  delay(delay_after_ms_u16);
}

//*************************************************************************//

