/* DHT control module */
#include "Sensor.h"

Sensor::Sensor()
       :__dht(DHT_PIN, DHT_TYPE){
  temperature = 0;
  humidity = 0;
}

void Sensor::Setup(){
  __dht.begin(); 
}

void Sensor::__getTemperatureAndHumidity(){
  humidity = CONFIG.DEMO_MODE_ON ? DemoFunc(25, 0, 100) : __dht.readHumidity();
  temperature = CONFIG.DEMO_MODE_ON ? DemoFunc(50, CONFIG.MIN_TEMP, CONFIG.MAX_TEMP) : __dht.readTemperature();
}

// update temperature and humidity
void Sensor::__displayUpdateTemperatureAndHumidity(){
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read data from DHT sensor !");
    return;
  }
  char str[5] = "";
  // update integer part of temperature
  sprintf(str, "%2d%s", (int8_t)temperature, temperature <= -10 ? "" : ".");

  // update temperature trend
  __trend.Update(temperature);

  NextText temp_int = NextText(HOME_TEMP_INT_TEXT.PAGE, HOME_TEMP_INT_TEXT.ID, HOME_TEMP_INT_TEXT.NAME);
  temp_int.setText(str);
  
  // hide float part of temperature when display 3 symbols
  if (temperature > -10){
    strcpy(str, "");
    sprintf(str, "%1d", (int8_t)((abs(temperature)-abs((int8_t)temperature))*10));
    NextText temp_float = NextText(HOME_TEMP_FLOAT_TEXT.PAGE, HOME_TEMP_FLOAT_TEXT.ID, HOME_TEMP_FLOAT_TEXT.NAME);
    temp_float.setText(str);
  } 

  // update humidity
  strcpy(str, "");
  sprintf(str, "%d%%", humidity);
  NextText humid = NextText(HOME_HUMIDITY_TEXT.PAGE, HOME_HUMIDITY_TEXT.ID, HOME_HUMIDITY_TEXT.NAME);
  humid.setText(str);

  // Compute heat index in Celsius
  float hic = __dht.computeHeatIndex(temperature, humidity, false);
  // update feel temperature
  strcpy(str, "");
  sprintf(str, "%2d", round(hic));
  NextText temp_feel = NextText(HOME_TEMP_FEEL_TEXT.PAGE, HOME_TEMP_FEEL_TEXT.ID, HOME_TEMP_FEEL_TEXT.NAME);
  temp_feel.setText(str);
}

// add temperature value to wave form
void Sensor::__displayUpdateTemperatureWaveForm(){
  if (isnan(temperature)) {
    Serial.println("Failed to read data from DHT sensor !");
    return;
  }
  
  byte temp = map(temperature, CONFIG.MIN_TEMP, CONFIG.MAX_TEMP, 0, HOME_WAVE_HEIGHT-HOME_WAVE_CHANNELS);
  if (temp < 0) temp = 0;

  // keep wave temp
//  CONFIG.WAVE_TEMP_LIST.add(temp); 

  NextWaveform wave = NextWaveform(HOME_TEMPERATURE_WAVE.PAGE, HOME_TEMPERATURE_WAVE.ID, HOME_TEMPERATURE_WAVE.NAME);
  
  for (byte i=0; i<HOME_WAVE_CHANNELS; i++){
    wave.addValue(i, temp+i);
  }
}

// add temperature value to wave form
void Sensor::__displayUpdateHumidityWaveForm(){
  if (isnan(humidity)) {
    Serial.println("Failed to read data from DHT sensor !");
    return;
  }
  byte humid = map(humidity, 0, 100, 0, HOME_WAVE_HEIGHT-HOME_WAVE_CHANNELS);

  NextWaveform wave = NextWaveform(HOME_HUMIDITY_WAVE.PAGE, HOME_HUMIDITY_WAVE.ID, HOME_HUMIDITY_WAVE.NAME);
  for (byte i=0; i<HOME_WAVE_CHANNELS; i++){
    wave.addValue(i, (byte)(humid+i));
  }
}

// restore wave forms graphics
void Sensor::RestoreWaves(){
//  debugPrintln("RESTORE TEMP WAVE");
//  // restore temp wave
//  NextWaveform wave = NextWaveform(HOME_TEMPERATURE_WAVE.PAGE, HOME_TEMPERATURE_WAVE.ID, HOME_TEMPERATURE_WAVE.NAME);
//  for (byte j=HOME_WAVE_WIDTH-1; j>0; j--){
//    for (byte i=0; i<HOME_WAVE_CHANNELS; i++){
//      wave.addValue(i, CONFIG.WAVE_TEMP_LIST.wave[j-1]+i);
//    }
//  }
//  debugPrintln("### END RESTORE TEMP WAVE ###");
}

void Sensor::Update(){
  __getTemperatureAndHumidity();
  __displayUpdateTemperatureAndHumidity();
  __displayUpdateTemperatureWaveForm();
  __displayUpdateHumidityWaveForm();
}
