#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <NextionLite.h>
#include <Arduino.h>
#include "Save.h"

//#include <MemoryFree.h>
void printMemory(const char* msg);

//class LimitedList{
//  public:
//    byte wave[195];
//    LimitedList();
//    void add(byte value);
//    
//  private:
//    byte __count;
//    byte __limit;
//};

/* inendifier of Nextion element */
struct nextidentifier{
  byte PAGE;
  byte ID;
  const char* NAME;
};

/* ==================== TIMER page ==================== */
/* buttons */
const nextidentifier TIMER_HOME_BUT = {4, 2, "b5"}; // Home button on timer page
const nextidentifier TIMER_CLOCK_BUT = {4, 3, "b0"}; // Clock button on timer page
/* text */
/* ==================================================== */

/* ==================== CLOCK page ==================== */
/* buttons */
const nextidentifier CLOCK_HOME_BUT = {5, 2, "b5"}; // Home button on clock page
const nextidentifier CLOCK_TIMER_BUT = {5, 3, "b0"}; // Timer button on clock page
/* variables */
const nextidentifier CLOCK_DAY_VAR = {5, 29, "day"}; // month day variable
const nextidentifier CLOCK_MONTH_VAR = {5, 25, "month"}; // month variable
const nextidentifier CLOCK_WEEKDAY_VAR = {5, 24, "weekday"}; // week day variable
/* text */
const nextidentifier CLOCK_HOURS_TEXT = {5, 16, "t2"}; // hours text
const nextidentifier CLOCK_MINUTES_TEXT = {5, 17, "t0"}; // minutes text
const nextidentifier CLOCK_SECONDS_TEXT = {5, 18, "t1"}; // seconds text
const nextidentifier CLOCK_MONTH_TEXT = {5, 21, "tMonth"}; // month day text
const nextidentifier CLOCK_YEAR_TEXT = {5, 22, "tYear"}; // year text
/* ==================================================== */

/* =================== SETTING 1 page =================== */
/* buttons */
const nextidentifier SET_1_HOME_BUT = {2, 2, "b0"}; // Home button on setting 1 page
const nextidentifier SET_1_SETTING_BUT = {2, 4, "b1"}; // Settings 1 button
const nextidentifier SET_1_RELAY_BUT = {2, 3, "bRelay"}; // Relay on/off button
/* images id */
const byte SET_1_RELAY_ON_BUTTON_IMG = 11; // relay button "on" background image 
const byte SET_1_RELAY_OFF_BUTTON_IMG = 12; // relay button "off" background image 
/* text */
const nextidentifier SET_1_TARGET_INT_TEXT = {2, 13, "t0"}; // target temerature integer part
const nextidentifier SET_1_TARGET_FLOAT_TEXT = {2, 22, "t5"}; // target temerature float part
const nextidentifier SET_1_HYST_INT_TEXT = {2, 17, "t1"}; // hysteresis integer part
const nextidentifier SET_1_HYST_FLOAT_TEXT = {1, 18, "t2"}; // hysteresis temerature float part
const nextidentifier SET_1_TIMEOUT_TEXT = {2, 21, "t4"}; // display timeout
/* ====================================================== */

/* =================== SETTING 2 page =================== */
/* buttons */
const nextidentifier SET_2_HOME_BUT = {3, 2, "b0"}; // Home button on setting 2 page
const nextidentifier SET_2_SETTING_BUT = {3, 3, "b1"}; // Settings 2 button
const nextidentifier SET_2_DEMO_BUT = {3, 4, "bDemo"}; // demo on/off button
/* images id */
const byte SET_2_DEMO_ON_BUTTON_IMG = 14; // demo button "on" background image 
const byte SET_2_DEMO_OFF_BUTTON_IMG = 13; // demo button "off" background image 
/* text */
const nextidentifier SET_2_SENSOR_INTERVAL_TEXT = {3, 15, "t1"}; // sensor interval
const nextidentifier SET_2_TREND_INTERVAL_TEXT = {3, 16, "t2"}; // trend interval
const nextidentifier SET_2_MAX_TEMP_TEXT = {3, 13, "t3"}; // max temerature threshold
const nextidentifier SET_2_MIN_TEMP_TEXT = {3, 14, "t0"}; // min temerature threshold
/* ====================================================== */

/* ===================== HOME page ==================== */
/* buttons */
const nextidentifier HOME_SETTIGNS_BUT = {1, 6, "b3"};
const nextidentifier HOME_TIMER_BUT = {1, 11, "b4"};
/* Relay Power and heater icons */
const nextidentifier HOME_RELAY_CONTROL_ICON_CROP = {1, 15, "qPower"}; // power on/off (relay control on/off) icons
const nextidentifier HOME_RELAY_ACTIVE_ICON_CROP = {1, 14, "qHeater"}; // (relay on/off) heater on/off icons
const nextidentifier HOME_TIME_ACTIVE_ICON_CROP = {1, 17, "qTimer"}; // (relay on/off) heater on/off icons
const byte HOME_RELAY_OFF_IMG = 0; // power off and heater off image 
const byte HOME_RELAY_ON_IMG = 1; // power on and heater on image 
/* date and time */
const nextidentifier HOME_TIME_TEXT = {1, 4, "tTime"};
const nextidentifier HOME_DATE_TEXT = {1, 12, "tDate"};
/* Temperature */
const nextidentifier HOME_TEMP_INT_TEXT = {1, 9, "tTempInt"}; // Integer part of temperature. Integer and float part display separately with different fonts.
const nextidentifier HOME_TEMP_FLOAT_TEXT = {1, 10, "tTempFloat"}; // float part of temperature.
const nextidentifier HOME_TEMP_FEEL_TEXT = {1, 5, "tFeel"}; // feel temperature.
const nextidentifier HOME_TARGET_TEMP_TEXT = {1, 7, "tTarget"}; // Target temperature
/* humidity */
const nextidentifier HOME_HUMIDITY_TEXT = {1, 3, "tHumid"}; // UI humidity 
/* WAVE form */
const nextidentifier HOME_TEMPERATURE_WAVE = {1, 2, "sWaveTemp"}; // wave temp
const nextidentifier HOME_HUMIDITY_WAVE = {1, 8, "sWaveHum"}; // wave humidity 
const byte HOME_WAVE_CHANNELS = 3; // draw to channels with 1 value Offset for increase line width
const byte HOME_WAVE_HEIGHT = 43; // height of wave form
const byte HOME_WAVE_WIDTH = 195; // width of wave form. Used for array of wave values
/* =================================================== */

/* ======================= Other ====================== */
const char* const WEEK_AND_MONTH_DISP[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday", 
                                           "January","February","March","April","May","June","July","August","September","October","November","December"};
enum HOME_TREND_IMAGES {TREND_EMPTY=4, TREND_UP=2, TREND_DOWN=0, TREND_FLAT=1}; // trend image ids
/* ==================================================== */

/* ================== SD CARD ======================== */
//const char* const TEMPERATURE_FILE = "TEMPERATURE.TXT";
//const char* const HUMIDITY_FILE = "HUMIDITY.TXT";
//const char* const RELAY_USAGE_FILE = "RELAY.TXT";
/* =================================================== */

/* ================== define ======================== */
#define RELAY_PIN 6 // relay pin
#define DHT_PIN 2 // DHT22 sensor pin
#define DHT_TYPE DHT22 // DHT22 sensor type
#define DS3231_I2C_ADDRESS 0x68 // DS3231 sensor address
#define CONFIG_RESET_PIN 3 // connect this pin with ground and restart Arduino board to reset config to default values
#define SDCARD_CS_PIN 4 // CS (Slave Select) PIN for CATALEX MicroSD Adapter (v1.0)
/* ================================================== */

/* ================ base page class ================= */
class BasePage{
  public:
    // nextion touch event list
    virtual NextTouch** getCallbackListenerList(){return NULL;};
    virtual void Update(){}; // loop update
    virtual void InitSetup(){}; // init setup when arduino starts
    virtual void OnPageLoad(){}; // page loading
    virtual void OnPageChange(const char *cmd){}; // change page with command for change page
    virtual ~BasePage(){};
};
/* ================================================== */

/* =========== dynamic config variables ============= */
#define EEPROM_BYTE_0 10 // first byte in eeprom. Dynamic config will be reset If byte 0 from eeprom doesn't equal this value.
#define EEPROM_BYTE_1 100 // second byte in eeprom. Dynamic config will be reset If byte 1 from eeprom doesn't equal this value.

// dynamic config saved in EEPROM
struct persists_config{
  bool DEMO_MODE_ON = false; // on/off demo mode 
  
  // relay 
  bool RELAY_MAY_ENABLED = true; //  is relay may be enabled
  float RELAY_HYSTERESIS = 1.2; // temerature hysteresis
  float RELAY_TARGET_TEMPERATURE = 25.0; // target temperature
  
  // display
  uint16_t DISPLAY_SLEEP_TIMEOUT = 0; // 0-999 sleep timeout. 0-disable
  
  // wave form
  uint16_t MAX_TEMP = 40; // max display temperature on wave form
  int16_t MIN_TEMP = 20; // min display temperature on wave form
  
  // intervals
  byte TIME_UPDATE_INTERVAL = 30; // 0-60 time interval in seconds for update time
  uint16_t SENSOR_UPDATE_INTERVAL = 300; // 0-65,535 time interval in seconds for update data from sensors
  uint16_t TREND_UPDATE_INTERVAL = 7200; // 0-65,535 time interval in seconds required for trend calculation
};
extern persists_config CONFIG;

// temporary dynamic config
struct temporary_config{
    // temperature trend 
    HOME_TREND_IMAGES CURRENT_TREND = TREND_FLAT; // current temperature trend
    // relay
    bool IS_RELAY_ENABLED = false; //  current relay status
    // SD Card available
    bool IS_SDCARD_AVAILABLE = false; 
    // wave form arrays
};
extern temporary_config LOCAL;
/* ================================================== */
#endif /* __CONFIG_H__ */
