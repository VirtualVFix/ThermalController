/* RTC DS3231 control module */
#ifndef __RTC_H__
#define __RTC_H__

//#include <DS3231.h>
#include <Wire.h>
#include "Config.h"

// time in real format
struct real_time{
  byte second;
  byte minute;
  byte hour;
  byte dayOfWeek;
  byte dayOfMonth;
  byte month;
  byte year;
};

class RTC{
  public:
    RTC();
    void Setup();
    void Update();
    // read time from sensor
    void readTime();
    // setup time to sensor
    void setTime();
    // time and date
    real_time r_time; 
  private:
    byte __decToBin(byte value);
    byte __binToDec(byte value);
};

#endif /* __RTC_H__ */

