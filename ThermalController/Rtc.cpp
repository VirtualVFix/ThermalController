/* RTC DS3231 control module */
#include "RTC.h"

RTC::RTC(){
  
}

void RTC::Setup(){
  Wire.begin(); 
}

byte RTC::__decToBin(byte value){
  return (value/10*16 + value%10);
}

byte RTC::__binToDec(byte value){
  return (value/16*10 + value%16);
}

// read time from sensor
void RTC::readTime(/*real_time *r_time*/){
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set DS3231 register to 00h
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  // request 7 bytes starting from 00h
  r_time.second = __binToDec(Wire.read() & 0x7f);
  r_time.minute = __binToDec(Wire.read());
  r_time.hour = __binToDec(Wire.read() & 0x3f);
  r_time.dayOfWeek = __binToDec(Wire.read());
  r_time.dayOfMonth = __binToDec(Wire.read());
  r_time.month = __binToDec(Wire.read());
  r_time.year = __binToDec(Wire.read());
}

// setup time to sensor
void RTC::setTime(/*real_time r_time*/){
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0);
  Wire.write(__decToBin(r_time.second));
  Wire.write(__decToBin(r_time.minute));
  Wire.write(__decToBin(r_time.hour));
  Wire.write(__decToBin(r_time.dayOfWeek)); // 1=Sunday, 7=Saturday
  Wire.write(__decToBin(r_time.dayOfMonth)); // 1-31
  Wire.write(__decToBin(r_time.month)); 
  Wire.write(__decToBin(r_time.year)); // 0 - 99
  Wire.endTransmission();
}

// update date and time on display
void RTC::Update(){
  readTime();
  char str[strlen(WEEK_AND_MONTH_DISP[3])+strlen(WEEK_AND_MONTH_DISP[15])+16];
  // update time "18 00"
  sprintf(str, "%02u %02u",
               r_time.hour,
               r_time.minute);
  NextText _time = NextText(HOME_TIME_TEXT.PAGE, HOME_TIME_TEXT.ID, HOME_TIME_TEXT.NAME);
  _time.setText(str);
  // update date: Monday 10-April
  strcpy(str, "");
  sprintf(str, "%s%s %02u-%s%s",
               CONFIG.DEMO_MODE_ON ? "DEMO " : "",
               WEEK_AND_MONTH_DISP[r_time.dayOfWeek-1],
               r_time.dayOfMonth,
               WEEK_AND_MONTH_DISP[6+r_time.month],
               CONFIG.DEMO_MODE_ON ? " DEMO" : "");
  NextText _date = NextText(HOME_DATE_TEXT.PAGE, HOME_DATE_TEXT.ID, HOME_DATE_TEXT.NAME);
  _date.setText(str);
}

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

