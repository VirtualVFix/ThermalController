/* RTC DS3231 control module */
#include "Datetime.h"

// alarm 1 callback
void alarm1Callback(){
  CONFIG.RELAY_MAY_ENABLED = true;
}

// alarm 2 callback
void alarm2Callback(){
  CONFIG.RELAY_MAY_ENABLED = false;
  saveConfig();
}

void Datetime::Setup(){
    RTC.pm = 0; // 24-hours time format
    
    // set timer callback
    RTC.setAlarm1Callback(alarm1Callback);
    RTC.setAlarm2Callback(alarm2Callback);
    
    UpdateIcon();
}

// update date and time on display
void Datetime::Update(){
  RTC.readTime();
  char str[strlen(WEEK_AND_MONTH_DISP[3])+strlen(WEEK_AND_MONTH_DISP[15])+16];
  // update time "18 00"
  sprintf(str, "%02u %02u",
               RTC.h,
               RTC.m);
  NextText _time = NextText(HOME_TIME_TEXT.PAGE, HOME_TIME_TEXT.ID, HOME_TIME_TEXT.NAME);
  _time.setText(str);
  // update date: Monday 10-April
  strcpy(str, "");
  sprintf(str, "%s%s %02u-%s%s",
               CONFIG.DEMO_MODE_ON ? "DEMO " : "",
               WEEK_AND_MONTH_DISP[RTC.dow-1],
               RTC.dd,
               WEEK_AND_MONTH_DISP[6+RTC.mm],
               CONFIG.DEMO_MODE_ON ? " DEMO" : "");
  NextText _date = NextText(HOME_DATE_TEXT.PAGE, HOME_DATE_TEXT.ID, HOME_DATE_TEXT.NAME);
  _date.setText(str);
}

// update timer icon
void Datetime::UpdateIcon(){
  NextCrop crop = NextCrop(HOME_TIMER_ACTIVE_ICON_CROP.PAGE, HOME_TIMER_ACTIVE_ICON_CROP.ID, HOME_TIMER_ACTIVE_ICON_CROP.NAME);
  crop.setImage(CONFIG.IS_TIMER_ENABLED ? HOME_ICONS_ON_IMG: HOME_ICONS_OFF_IMG);
}


//// read time from sensor
//void RTC::readTime(/*real_time *r_time*/){
//  Wire.beginTransmission(DS3231_I2C_ADDRESS);
//  Wire.write(0); // set DS3231 register to 00h
//  Wire.endTransmission();
//  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
//  // request 7 bytes starting from 00h
//  r_time.second = __binToDec(Wire.read() & 0x7f);
//  r_time.minute = __binToDec(Wire.read());
//  r_time.hour = __binToDec(Wire.read() & 0x3f);
//  r_time.dayOfWeek = __binToDec(Wire.read());
//  r_time.dayOfMonth = __binToDec(Wire.read());
//  r_time.month = __binToDec(Wire.read());
//  r_time.year = __binToDec(Wire.read());
//}
//
//// setup time to sensor
//void RTC::setTime(/*real_time r_time*/){
//  Wire.beginTransmission(DS3231_I2C_ADDRESS);
//  Wire.write(0);
//  Wire.write(__decToBin(r_time.second));
//  Wire.write(__decToBin(r_time.minute));
//  Wire.write(__decToBin(r_time.hour));
//  Wire.write(__decToBin(r_time.dayOfWeek)); // 1=Sunday, 7=Saturday
//  Wire.write(__decToBin(r_time.dayOfMonth)); // 1-31
//  Wire.write(__decToBin(r_time.month)); 
//  Wire.write(__decToBin(r_time.year)); // 0 - 99
//  Wire.endTransmission();
//}

///* RTC DS3231 control module */
//#include "RTC.h"
//
//void RTC::Setup(){
//  Wire.begin(); 
//}
//
//// update date and time on display  
//void RTC::Update(){
//  DS3231 rtc;
//  bool _false = false;
//  char str[strlen(WEEK_AND_MONTH_DISP[3])+strlen(WEEK_AND_MONTH_DISP[15])+6];
//  // update time "18 00"
//  sprintf(str, "%02u %02u",
//               rtc.getHour(_false, _false),
//               rtc.getMinute());
//  NextText _time = NextText(NEXT_TIME_IDS.PAGE, NEXT_TIME_IDS.ID, NEXT_TIME_IDS.NAME);
//  _time.setText(str);
//  // update date: Monday 10-April
//  strcpy(str, "");
//  sprintf(str, "%s%s %02u-%s%s",
//               CONFIG.DEMO_MODE_ON ? "DEMO " : "",
//               WEEK_AND_MONTH_DISP[rtc.getDoW()-1],
//               rtc.getDate(),
//               WEEK_AND_MONTH_DISP[6+rtc.getMonth(_false)],
//               CONFIG.DEMO_MODE_ON ? " DEMO" : "");
//  NextText _date = NextText(NEXT_DATE_IDS.PAGE, NEXT_DATE_IDS.ID, NEXT_DATE_IDS.NAME);
//  _date.setText(str);
//}
