
#include <EEPROM.h>

#include "config.h"

tt_eep_configData_t tt_eep_cfgData[TT_EEP_CFG_IDX_MAX+1];

uint16_t tt_eep_cfgStart_addr_u16 = 0;
uint16_t eep_size_u16 = 4095;

void eraseTTEEPConfig()
{
  // Reset EEPROM bytes to '0' for the length of the data structure
  EEPROM.begin(eep_size_u16);
  for (uint8_t i = tt_eep_cfgStart_addr_u16 ; i < sizeof(tt_eep_cfgData) ; i++)
  {
    EEPROM.write(i, 0x00); // set 
  }
  delay(200);
  EEPROM.commit();
  EEPROM.end();
}

void saveTTEEPConfig()
{
  // Save configuration from RAM into EEPROM
  EEPROM.begin(eep_size_u16);
  EEPROM.put(tt_eep_cfgStart_addr_u16, tt_eep_cfgData);
  delay(200);
  EEPROM.commit();                      // Only needed for ESP8266 to get data written
  EEPROM.end();                         // Free RAM copy of structure
}

void loadTTEEPConfig()
{
  // Loads configuration from EEPROM into RAM
  EEPROM.begin(eep_size_u16);
  EEPROM.get(tt_eep_cfgStart_addr_u16, tt_eep_cfgData);
  EEPROM.end();
}

boolean setTTEEPDefaultCfg(uint8_t idx_u8)
{
  if (idx_u8 > TT_EEP_CFG_IDX_MAX)
    return false;

  tt_eep_cfgData[idx_u8].enabled_on_start_b    = true;
  tt_eep_cfgData[idx_u8].dir_in_start_b        = false;
  tt_eep_cfgData[idx_u8].delay_after_ms_u16    = 100;
  tt_eep_cfgData[idx_u8].delay_between_us_u16  = 5;
  tt_eep_cfgData[idx_u8].ms_bm_u8              = 0x00;

  return true;
}

boolean setTTEEPConfig(tt_eep_configData_t cfg, uint8_t idx_u8)
{
  if (idx_u8 > TT_EEP_CFG_IDX_MAX)
    return false;

  tt_eep_cfgData[idx_u8].enabled_on_start_b    = cfg.enabled_on_start_b;
  tt_eep_cfgData[idx_u8].dir_in_start_b        = cfg.dir_in_start_b;
  tt_eep_cfgData[idx_u8].delay_after_ms_u16    = cfg.delay_after_ms_u16;
  tt_eep_cfgData[idx_u8].delay_between_us_u16  = cfg.delay_between_us_u16;
  tt_eep_cfgData[idx_u8].ms_bm_u8              = cfg.ms_bm_u8;

  return true;
}

tt_eep_configData_t getTTEEPConfig(uint8_t idx_u8)
{
	return tt_eep_cfgData[idx_u8];
}

