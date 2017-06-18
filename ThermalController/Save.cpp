#include "Save.h"

// read dynamic config variables
void readConfig(){
  dinamic_config conf;
  EEPROM.get(0, conf);

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
//  debugPrintln(conf.MAX_WAVE_TEMP);
//  debugPrint("MIN_WAVE_TEMP: ");
//  debugPrintln(conf.MIN_WAVE_TEMP);
//  debugPrint("TIME_UPDATE_INTERVAL: ");
//  debugPrintln(conf.TIME_UPDATE_INTERVAL);
//  debugPrint("SENSOR_UPDATE_INTERVAL: ");
//  debugPrintln(conf.SENSOR_UPDATE_INTERVAL);
//  debugPrint("TREND_UPDATE_INTERVAL: ");
//  debugPrintln(conf.TREND_UPDATE_INTERVAL);

  if ((byte)conf.DEMO_MODE_ON <= 1){
    CONFIG = conf;
  }
}

// save dynamic config variables
void saveConfig(){
//  debugPrintln("SAVE CONFIG");
  EEPROM.put(0, CONFIG);
}

// reset config to default values
void resetConfig(){
//  debugPrintln("RESET CONFIG");
  dinamic_config conf;
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
