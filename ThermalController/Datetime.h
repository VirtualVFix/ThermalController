/* RTC DS3231 control module */
#ifndef __DATETIME_H__
#define __DATETIME_H__

#include "Config.h"
#include <MD_DS3231.h>

class Datetime{
  public:
    void Setup();
    void Update();
    void UpdateIcon();
};

#endif /* __DATETIME_H__ */

