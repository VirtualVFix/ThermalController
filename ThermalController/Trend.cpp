#include "Trend.h"

Trend::Trend(){
  this->__trend_timestamp = 0;
  this->__currentTrend = CONFIG.CURRENT_TREND;
  this->__trendDelta = 0;
  this->__previousTemp = 0;
  this->__firstCall = true;
}

// calculate current trend
void Trend::__calculateTrend(){
  if (millis()-__trend_timestamp > (CONFIG.DEMO_MODE_ON ? 1000 : (unsigned long) CONFIG.TREND_UPDATE_INTERVAL*1000)){
    if ((int)__trendDelta < 0){
      this->__currentTrend = TREND_UP;
    }else if ((int)__trendDelta > 0){
      this->__currentTrend = TREND_DOWN;
    }else{
      this->__currentTrend = TREND_FLAT;
    }
    this->__trendDelta = 0;
    this->__trend_timestamp = millis();
    CONFIG.CURRENT_TREND = __currentTrend;
  }
}

void Trend::Update(float &temperature){
  // ignore first call of function when previous temperature is N/A 
  if (__firstCall){
    this->__previousTemp = temperature;
    this->__firstCall = false;
  }
  
  // calc trend delta
  this->__trendDelta += __previousTemp-temperature;
  this->__previousTemp = temperature; 
  
  // calculate temperature trend
  __calculateTrend();
  
  // update trend
  NextText text_int = NextText(HOME_TEMP_INT_TEXT.PAGE, HOME_TEMP_INT_TEXT.ID, HOME_TEMP_INT_TEXT.NAME);
  if (temperature <= -10){
    text_int.setBackground(TREND_EMPTY);
  }else{
    NextText text_float = NextText(HOME_TEMP_FLOAT_TEXT.PAGE, HOME_TEMP_FLOAT_TEXT.ID, HOME_TEMP_FLOAT_TEXT.NAME);
    text_int.setBackground(__currentTrend);
    text_float.setBackground(__currentTrend);
  }
}

