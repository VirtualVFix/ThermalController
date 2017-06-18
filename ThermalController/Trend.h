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
    HOME_TREND_IMAGES __currentTrend; // current temperature trend
    unsigned long __trend_timestamp; // trend update timestamp
    float __trendDelta; // delta for calc trend
    float __previousTemp;
    bool __firstCall; // ignore first call of function when previous temperature is N/A 
    void __calculateTrend();
};

#endif /* __TREND_H__ */
