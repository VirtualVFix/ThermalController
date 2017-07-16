/* home page control module */
#include "HomePage.h"

HomePage::HomePage(ObjectCallback settingsCallback, ObjectCallback timerCallback){
  // buttons
  this->__settingButton = new NextButton(HOME_SETTIGNS_BUT.PAGE, HOME_SETTIGNS_BUT.ID, HOME_SETTIGNS_BUT.NAME);
  this->__timerButton = new NextButton(HOME_TIMER_BUT.PAGE, HOME_TIMER_BUT.ID, HOME_TIMER_BUT.NAME);

  // add button callback
  this->__settingButton->addReleaseCallback(settingsCallback);
  this->__timerButton->addReleaseCallback(timerCallback);
  
  // timestamps
  this->__sensor_update_timestamp = 0;
  this->__time_update_timestamp = 0;
  
  // add callback to listener
  this->__callback_listener_list[0] = this->__settingButton;
  this->__callback_listener_list[1] = this->__timerButton;
  this->__callback_listener_list[2] = NULL;
}

HomePage::~HomePage(){
  delete this->__settingButton;
  delete this->__timerButton;
}

void HomePage::InitSetup(){   
  // relay setup
  __relay.Setup();

  // rtc setup
  __rtc.Setup();

  // sensor setup
  __sensor.Setup();

  // set display timeout
  char str[10];
  sprintf(str, "thsp=%d", CONFIG.DISPLAY_SLEEP_TIMEOUT);
  sendCommand(str);
}

NextTouch** HomePage::getCallbackListenerList(){
  return __callback_listener_list;
}

void HomePage::OnPageLoad(){
  // skip loading 
  sendCommand("sys0=1");
    
  // update target temperature
  NextText target = NextText(HOME_TARGET_TEMP_TEXT.PAGE, HOME_TARGET_TEMP_TEXT.ID, HOME_TARGET_TEMP_TEXT.NAME);
  char str[6];
  sprintf(str, "%d.%01d", (int)CONFIG.RELAY_TARGET_TEMPERATURE, (int)(CONFIG.RELAY_TARGET_TEMPERATURE*10)%10);
  target.setText(str);
  
  // update relay icons
  __relay.UpdateIcons();

  // restore waves graphics
  __sensor.RestoreWaves();
}

void HomePage::OnPageChange(const char *cmd){
  // change page
  sendCommand(cmd);
}

void HomePage::Update(){
  if (__time_update_timestamp == 0 || millis()-__time_update_timestamp > (unsigned long)CONFIG.TIME_UPDATE_INTERVAL*1000){
    __rtc.Update();
    this->__time_update_timestamp = millis();    
  }
  if (__sensor_update_timestamp == 0 || millis()-__sensor_update_timestamp > (CONFIG.DEMO_MODE_ON ? 300:(unsigned long)CONFIG.SENSOR_UPDATE_INTERVAL*1000)){
    __sensor.Update();
    __relay.Update(__sensor.temperature);  
    this->__sensor_update_timestamp = millis();    
  }
}
