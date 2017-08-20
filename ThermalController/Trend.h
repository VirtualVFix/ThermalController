/* temperature trend module */ 
#ifndef __TREND_H__
#define __TREND_H__

#include "Config.h"

class Trend{    
  public:
    Trend();
    // calc and update temperature trend image
    void Update(float &temperature);
    
  private:
    unsigned long __trend_timestamp; // trend update timestamp
    float __previousTemp;
    void __calculateTrend();
};

#endif /* __TREND_H__ */
