#include "Setting2Page.h"

Setting2Page::Setting2Page(ObjectCallback homeCallback, ObjectCallback settingCallback){
  // buttons
  this->__homeButton = new NextButton(SET_2_HOME_BUT.PAGE, SET_2_HOME_BUT.ID, SET_2_HOME_BUT.NAME);
  this->__settingButton = new NextButton(SET_2_SETTING_BUT.PAGE, SET_2_SETTING_BUT.ID, SET_2_SETTING_BUT.NAME);

  // add button callback
  this->__homeButton->addReleaseCallback(homeCallback);
  this->__settingButton->addReleaseCallback(settingCallback);
  
  // add callback to listener
  this->__callback_listener_list[0] = this->__homeButton;
  this->__callback_listener_list[1] = this->__settingButton;
  this->__callback_listener_list[2] = NULL;
}

Setting2Page::~Setting2Page(){
  delete this->__homeButton;
  delete this->__settingButton;
  for (byte i=0; i<sizeof(__callback_listener_list)/sizeof(*__callback_listener_list); i++){
    this->__callback_listener_list[i] = NULL;
  }
}

void Setting2Page::OnPageLoad(){
  NextText sensor = NextText(SET_2_SENSOR_INTERVAL_TEXT.PAGE, SET_2_SENSOR_INTERVAL_TEXT.ID, SET_2_SENSOR_INTERVAL_TEXT.NAME);
  NextText trend = NextText(SET_2_TREND_INTERVAL_TEXT.PAGE, SET_2_TREND_INTERVAL_TEXT.ID, SET_2_TREND_INTERVAL_TEXT.NAME);
  NextButton demo = NextButton(SET_2_DEMO_BUT.PAGE, SET_2_DEMO_BUT.ID, SET_2_DEMO_BUT.NAME);
  NextText max_temp = NextText(SET_2_MAX_TEMP_TEXT.PAGE, SET_2_MAX_TEMP_TEXT.ID, SET_2_MAX_TEMP_TEXT.NAME);
  NextText min_temp = NextText(SET_2_MIN_TEMP_TEXT.PAGE, SET_2_MIN_TEMP_TEXT.ID, SET_2_MIN_TEMP_TEXT.NAME);  
  
  // sensor interval (in seconds)
  char str[5];
  memset(str, 0, sizeof str);
  sprintf(str, "%d", CONFIG.SENSOR_UPDATE_INTERVAL);
  sensor.setText(str);

  // trend interval (in minutes)
  memset(str, 0, sizeof str);
  sprintf(str, "%d", CONFIG.TREND_UPDATE_INTERVAL/60);
  trend.setText(str);

  // max temperature
  memset(str, 0, sizeof str);
  sprintf(str, "%d", CONFIG.MAX_TEMP);
  max_temp.setText(str);

  // min temperature
  memset(str, 0, sizeof str);
  sprintf(str, "%d", CONFIG.MIN_TEMP);
  min_temp.setText(str);

  // set demo button state
  demo.setBackground(CONFIG.DEMO_MODE_ON ? SET_2_DEMO_ON_BUTTON_IMG : SET_2_DEMO_OFF_BUTTON_IMG);
}

void Setting2Page::OnPageChange(const char *cmd){
  // get sensor interval (in seconds)
  NextText sensor = NextText(SET_2_SENSOR_INTERVAL_TEXT.PAGE, SET_2_SENSOR_INTERVAL_TEXT.ID, SET_2_SENSOR_INTERVAL_TEXT.NAME);
  char str[5];
  memset(str, 0, sizeof str);
  if (sensor.getText(str, 5) == 0){
//    debugPrintln("Error get sensor interval from display !");
  }else{
    CONFIG.SENSOR_UPDATE_INTERVAL = atoi(str)==0 ? 1 : atoi(str);
  }
  
  // get trend interval (in minutes)
  NextText trend = NextText(SET_2_TREND_INTERVAL_TEXT.PAGE, SET_2_TREND_INTERVAL_TEXT.ID, SET_2_TREND_INTERVAL_TEXT.NAME);
  memset(str, 0, sizeof str);
  if (trend.getText(str, 5) == 0){
//    debugPrintln("Error get trend interval from display !");
  }else{
    CONFIG.TREND_UPDATE_INTERVAL = atoi(str)==0 ? 60 :  atoi(str)*60;
  }
  
  // get max temperature
  NextText max_temp = NextText(SET_2_MAX_TEMP_TEXT.PAGE, SET_2_MAX_TEMP_TEXT.ID, SET_2_MAX_TEMP_TEXT.NAME);
  memset(str, 0, sizeof str);
  if (max_temp.getText(str, 5) == 0){
//    debugPrintln("Error get max temperature from display !");
  }else{
    CONFIG.MAX_TEMP = (uint16_t)atoi(str);
  }
  
  // get min temperature
  NextText min_temp = NextText(SET_2_MIN_TEMP_TEXT.PAGE, SET_2_MIN_TEMP_TEXT.ID, SET_2_MIN_TEMP_TEXT.NAME);
  memset(str, 0, sizeof str);
  if (min_temp.getText(str, 5) == 0){
//    debugPrintln("Error get min temperature from display !");
  }else{
    CONFIG.MIN_TEMP = (int16_t)atoi(str);
  }
  
  // get demo button status
  NextButton demo = NextButton(SET_2_DEMO_BUT.PAGE, SET_2_DEMO_BUT.ID, SET_2_DEMO_BUT.NAME);
  uint32_t img = SET_2_DEMO_ON_BUTTON_IMG+SET_2_DEMO_OFF_BUTTON_IMG;
  demo.getBackground(img);
  if (img == SET_2_DEMO_ON_BUTTON_IMG){
    CONFIG.DEMO_MODE_ON = true;
  }else if (img == SET_2_DEMO_OFF_BUTTON_IMG){
    CONFIG.DEMO_MODE_ON = false;
  }else{
//    debugPrintln("Error get demo mode on/off button status from display !");
  }

  // save
  saveConfig();

  // change page
  sendCommand(cmd);
}

NextTouch** Setting2Page::getCallbackListenerList(){
  return __callback_listener_list;
}

void Setting2Page::Update(){
//  printMemory("Setting 2 update");
//  delay(500);
}

