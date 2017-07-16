#include "Save.h"

// read dynamic config variables
void readConfig(){
  persists_config conf;
  byte b0=0;
  byte b1=0;
  // reset config on first load
  EEPROM.get(0, b0);
  EEPROM.get(1, b1);
  if (b0 != EEPROM_BYTE_0 && b1 != EEPROM_BYTE_1){
    resetConfig();
    EEPROM.update(0, EEPROM_BYTE_0);
    EEPROM.update(1, EEPROM_BYTE_1);
  }
  EEPROM.get(2, conf);

//  debugPrintln("READ CONFIG");
//  debugPrint("DEMO_MODE_ON: ");
//  debugPrintln(conf.DEMO_MODE_ON);
//  debugPrint("RELAY_MAY_ENABLED: ");
//  debugPrintln(conf.RELAY_MAY_ENABLED);
//  debugPrint("RELAY_HYSTERESIS: ");
//  debugPrintln(conf.RELAY_HYSTERESIS);
//  debugPrint("RELAY_TARGET_TEMPERATURE: ");
//  debugPrintln(conf.RELAY_TARGET_TEMPERATURE);
//  debugPrint("DISPLAY_SLEEP_TIMEOUT: ");
//  debugPrintln(conf.DISPLAY_SLEEP_TIMEOUT);
//  debugPrint("MAX_WAVE_TEMP: ");
//  debugPrintln(conf.MAX_TEMP);
//  debugPrint("MIN_WAVE_TEMP: ");
//  debugPrintln(conf.MIN_TEMP);
//  debugPrint("TIME_UPDATE_INTERVAL: ");
//  debugPrintln(conf.TIME_UPDATE_INTERVAL);
//  debugPrint("SENSOR_UPDATE_INTERVAL: ");
//  debugPrintln(conf.SENSOR_UPDATE_INTERVAL);
//  debugPrint("TREND_UPDATE_INTERVAL: ");
//  debugPrintln(conf.TREND_UPDATE_INTERVAL);

  CONFIG = conf;
}

// save dynamic config variables
void saveConfig(){
//  debugPrintln("SAVE CONFIG");
  EEPROM.put(2, CONFIG);
}

// reset config to default values
void resetConfig(){
  debugPrintln("RESET CONFIG");
  persists_config conf;
  CONFIG = conf;
  saveConfig();
}

// read data for temperature and hymidity wave forms
void readWaveDataConfig(){
//  debugPrintln("READ WAVE FORM CONFIG");
}

// save data from temperature and hymidity wave forms
void saveWaveDataConfig(){
//  debugPrintln("SAVE WAVE FORM CONFIG");
}

// reset data from temperature and hymidity wave forms to default values
void resetWaveDataConfig(){
//  debugPrintln("RESET WAVE FORM CONFIG");
  saveWaveDataConfig();
}
