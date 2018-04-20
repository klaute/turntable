
#ifndef _CONFIG_H_
#define _CONFIG_H_

#define DEBUG 1

#define TT_EEP_CFG_IDX_MAX 2

#define STATUS_OUTPUT_DELAY_MS 5000UL

#define STATUS_LED_PIN        BUILTIN_LED

#define MS1_PIN               D0
#define MS2_PIN               D1
#define MS3_PIN               D2
#define STEP_PIN              D5
#define DIR_PIN               D6

String DEVICE_NAME            = "turntable";

typedef struct tt_eep_configData_t
{
  boolean  enabled_on_start_b;
  boolean  dir_in_start_b;
  uint16_t delay_after_ms_u16;
  uint8_t  delay_between_us_u16;
  uint8_t  ms_bm_u8;
};

#endif

