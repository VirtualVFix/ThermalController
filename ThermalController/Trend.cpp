#include "Trend.h"

Trend::Trend(){
  this->__trend_timestamp = 0;
  this->__previousTemp = 888;
}

// calculate current trend
void Trend::__calculateTrend(){
  if (millis()-__trend_timestamp > (CONFIG.DEMO_MODE_ON ? 1000 : (unsigned long) CONFIG.TREND_UPDATE_INTERVAL*1000)){
    if ((int)LOCAL.TREND_DELTA < 0){
      LOCAL.CURRENT_TREND = TREND_UP;
    }else if ((int)LOCAL.TREND_DELTA > 0){
      LOCAL.CURRENT_TREND = TREND_DOWN;
    }else{
      LOCAL.CURRENT_TREND = TREND_FLAT;
    }
    LOCAL.TREND_DELTA = 0;
    __trend_timestamp = millis();
  }
}

void Trend::Update(float &temperature){
  // ignore first call of function when previous temperature is N/A 
  if (__previousTemp == 888){
    __previousTemp = temperature;
  }
  
  // calc trend delta
  LOCAL.TREND_DELTA += __previousTemp-temperature;
  __previousTemp = temperature; 
  
  // calculate temperature trend
  __calculateTrend();
  
  // update trend
  NextText text_int = NextText(HOME_TEMP_INT_TEXT.PAGE, HOME_TEMP_INT_TEXT.ID, HOME_TEMP_INT_TEXT.NAME);
  if (temperature <= -10){
    text_int.setBackground(TREND_EMPTY);
  }else{
    NextText text_float = NextText(HOME_TEMP_FLOAT_TEXT.PAGE, HOME_TEMP_FLOAT_TEXT.ID, HOME_TEMP_FLOAT_TEXT.NAME);
    text_int.setBackground(LOCAL.CURRENT_TREND);
    text_float.setBackground(LOCAL.CURRENT_TREND);
  }
}
