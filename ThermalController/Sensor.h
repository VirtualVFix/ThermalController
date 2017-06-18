/* DHT control module */
#ifndef __SENSOR_H__
#define __SENSOR_H__

#include <DHT.h>
#include "Config.h"
#include "Demo.h"
#include "Trend.h"

class Sensor{
  public:
    float temperature;
    byte humidity;
    
    Sensor();
    void Setup();
    void Update();
    void RestoreWaves(); // restore wave forms graphics

  private:
    DHT __dht;
    // temperature trend 
    Trend __trend;
        
    void __displayUpdateTemperatureAndHumidity();
    void __displayUpdateTemperatureWaveForm();
    void __displayUpdateHumidityWaveForm();
    void __getTemperatureAndHumidity();
};

#endif /* __SENSOR_H__ */
