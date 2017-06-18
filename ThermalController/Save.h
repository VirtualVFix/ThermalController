#ifndef __SAVE_H__
#define __SAVE_H__

#include <EEPROM.h>
#include "Config.h"

void readConfig(); // read dynamic config variables 
void saveConfig(); // save dynamic config variables 
void resetConfig(); // reset config to default values
    
void readWaveDataConfig(); // read data for temperature and hymidity wave forms
void saveWaveDataConfig(); // save data from temperature and hymidity wave forms
void resetWaveDataConfig(); // reset data from temperature and hymidity wave forms to default values

#endif
