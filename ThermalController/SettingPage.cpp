#include "SettingPage.h"

SettingPage::SettingPage(ObjectCallback homeCallback, ObjectCallback settingCallback){
  // buttons
  this->__homeButton = new NextButton(SET_1_HOME_BUT.PAGE, SET_1_HOME_BUT.ID, SET_1_HOME_BUT.NAME);
  this->__settingButton = new NextButton(SET_1_SETTING_BUT.PAGE, SET_1_SETTING_BUT.ID, SET_1_SETTING_BUT.NAME);

  // add button callback
  this->__homeButton->addReleaseCallback(homeCallback);
  this->__settingButton->addReleaseCallback(settingCallback);
  
  // add callback to listener
  this->__callback_listener_list[0] = this->__homeButton;
  this->__callback_listener_list[1] = this->__settingButton;
  this->__callback_listener_list[2] = NULL;
}

SettingPage::~SettingPage(){
  delete this->__homeButton;
  delete this->__settingButton;
  for (byte i=0; i<sizeof(__callback_listener_list)/sizeof(*__callback_listener_list); i++){
    this->__callback_listener_list[i] = NULL;
  }
}

void SettingPage::OnPageLoad(){
  NextText target_int = NextText(SET_1_TARGET_INT_TEXT.PAGE, SET_1_TARGET_INT_TEXT.ID, SET_1_TARGET_INT_TEXT.NAME);
  NextText target_float = NextText(SET_1_TARGET_FLOAT_TEXT.PAGE, SET_1_TARGET_FLOAT_TEXT.ID, SET_1_TARGET_FLOAT_TEXT.NAME);
  NextText hyst_int = NextText(SET_1_HYST_INT_TEXT.PAGE, SET_1_HYST_INT_TEXT.ID, SET_1_HYST_INT_TEXT.NAME);
  NextText hyst_float = NextText(SET_1_HYST_FLOAT_TEXT.PAGE, SET_1_HYST_FLOAT_TEXT.ID, SET_1_HYST_FLOAT_TEXT.NAME);
  NextButton relay = NextButton(SET_1_RELAY_BUT.PAGE, SET_1_RELAY_BUT.ID, SET_1_RELAY_BUT.NAME);
 
  // set target tempatarute
  char str[5];
  memset(str, 0, sizeof str);
  sprintf(str, "%d", (int)CONFIG.RELAY_TARGET_TEMPERATURE);
  target_int.setText(str);
  memset(str, 0, sizeof str);
  sprintf(str, "%d", (int)round((CONFIG.RELAY_TARGET_TEMPERATURE-(int)CONFIG.RELAY_TARGET_TEMPERATURE)*10));
  target_float.setText(str);
  
  // set hysteresis
  memset(str, 0, sizeof str);
  sprintf(str, "%d", (int)CONFIG.RELAY_HYSTERESIS);  
  hyst_int.setText(str);
  memset(str, 0, sizeof str);
  sprintf(str, "%d", (int)round((CONFIG.RELAY_HYSTERESIS-(int)CONFIG.RELAY_HYSTERESIS)*10));
  hyst_float.setText(str);
  
  // set relay button state
  relay.setBackground(CONFIG.RELAY_MAY_ENABLED ? SET_1_RELAY_ON_BUTTON_IMG : SET_1_RELAY_OFF_BUTTON_IMG);
}

void SettingPage::OnPageChange(const char *cmd){
  // get target tempatarute
  NextText target_int = NextText(SET_1_TARGET_INT_TEXT.PAGE, SET_1_TARGET_INT_TEXT.ID, SET_1_TARGET_INT_TEXT.NAME);
  NextText target_float = NextText(SET_1_TARGET_FLOAT_TEXT.PAGE, SET_1_TARGET_FLOAT_TEXT.ID, SET_1_TARGET_FLOAT_TEXT.NAME);
  
  char str[5];
  String res = "";
  bool error = false;
  memset(str, 0, sizeof str);
  error |= target_int.getText(str, 5) == 0;
  res += str;
  res += ".";
  memset(str, 0, sizeof str);
  error |= target_float.getText(str, 5) == 0;
  res += str;
  
  if (error){
//    debugPrintln("Error get target temperature from display !");
  }else{
    CONFIG.RELAY_TARGET_TEMPERATURE = atof(res.c_str());
  }
  
  // get hysteresis
  NextText hyst_int = NextText(SET_1_HYST_INT_TEXT.PAGE, SET_1_HYST_INT_TEXT.ID, SET_1_HYST_INT_TEXT.NAME);
  NextText hyst_float = NextText(SET_1_HYST_FLOAT_TEXT.PAGE, SET_1_HYST_FLOAT_TEXT.ID, SET_1_HYST_FLOAT_TEXT.NAME);
  
  error = false;
  res = "";
  memset(str, 0, sizeof str);
  error |= hyst_int.getText(str, 5) == 0;
  res += str; 
  res += ".";
  memset(str, 0, sizeof str);
  error |= hyst_float.getText(str, 5) == 0;
  res += str;
  
  if (error){
//    debugPrintln("Error get hysteresis from display !");
  }else{
    CONFIG.RELAY_HYSTERESIS = atof(res.c_str());
  }

  // get display timeout
  NextText timeout = NextText(SET_1_TIMEOUT_TEXT.PAGE, SET_1_TIMEOUT_TEXT.ID, SET_1_TIMEOUT_TEXT.NAME);
  memset(str, 0, sizeof str);

  if (timeout.getText(str, 5) == 0){
//    debugPrintln("Error get timeout from display !");
  }else{
    CONFIG.DISPLAY_SLEEP_TIMEOUT = atoi(str);
  }

  // get relay state
  NextButton relay = NextButton(SET_1_RELAY_BUT.PAGE, SET_1_RELAY_BUT.ID, SET_1_RELAY_BUT.NAME);
  uint32_t img = SET_1_RELAY_ON_BUTTON_IMG+SET_1_RELAY_OFF_BUTTON_IMG;
  relay.getBackground(img);
  if (img == SET_1_RELAY_ON_BUTTON_IMG){
    CONFIG.RELAY_MAY_ENABLED = true;
  }else if (img == SET_1_RELAY_OFF_BUTTON_IMG){
    CONFIG.RELAY_MAY_ENABLED = false;
  }else{
//    debugPrintln("Error get relay on/off button status from display !");
  }
  
  // save
  saveConfig();

  // change page 
  sendCommand(cmd);
}

NextTouch** SettingPage::getCallbackListenerList(){
  return __callback_listener_list;
}

void SettingPage::Update(){
//  printMemory("Setting update");
//  delay(500);
}
