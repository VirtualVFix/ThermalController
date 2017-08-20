#include "TimerPage.h"

TimerPage::TimerPage(ObjectCallback homeCallback, ObjectCallback clockCallback){
  // buttons
  this->__homeButton = new NextButton(TIMER_HOME_BUT.PAGE, TIMER_HOME_BUT.ID, TIMER_HOME_BUT.NAME);
  this->__clockButton = new NextButton(TIMER_CLOCK_BUT.PAGE, TIMER_CLOCK_BUT.ID, TIMER_CLOCK_BUT.NAME);

  // add button callback
  this->__homeButton->addReleaseCallback(homeCallback);
  this->__clockButton->addReleaseCallback(clockCallback);
  
  // add callback to listener
  this->__callback_listener_list[0] = this->__homeButton;
  this->__callback_listener_list[1] = this->__clockButton;
  this->__callback_listener_list[2] = NULL;
}

TimerPage::~TimerPage(){ 
  delete this->__homeButton;
  delete this->__clockButton;
  for (byte i=0; i<sizeof(__callback_listener_list)/sizeof(*__callback_listener_list); i++){
    this->__callback_listener_list[i] = NULL;
  }
}

void TimerPage::OnPageLoad(){
  NextText shour = NextText(TIMER_START_HOUR_TEXT.PAGE, TIMER_START_HOUR_TEXT.ID, TIMER_START_HOUR_TEXT.NAME); // Start timer hour
  NextText smin = NextText(TIMER_START_MIN_TEXT.PAGE, TIMER_START_MIN_TEXT.ID, TIMER_START_MIN_TEXT.NAME); // Start timer minute
  NextText ehour = NextText(TIMER_END_HOUR_TEXT.PAGE, TIMER_END_HOUR_TEXT.ID, TIMER_END_HOUR_TEXT.NAME); // End timer hour
  NextText emin = NextText(TIMER_END_MIN_TEXT.PAGE, TIMER_END_MIN_TEXT.ID, TIMER_END_MIN_TEXT.NAME); // End timer minutes
  NextButton timer = NextButton(TIMER_TIMER_BUT.PAGE, TIMER_TIMER_BUT.ID, TIMER_TIMER_BUT.NAME); // timer button
  
  // set timer button state
  timer.setBackground(CONFIG.IS_TIMER_ENABLED ? TIMER_TIMER_ON_BUTTON_IMG : TIMER_TIMER_OFF_BUTTON_IMG);

  // start time
  RTC.readAlarm1();
  char str[6];
  memset(str, 0, sizeof str);
  sprintf(str, "%02u", RTC.h);
  shour.setText(str);
  
  memset(str, 0, sizeof str);
  sprintf(str, "%02u", RTC.m);
  smin.setText(str);
  
  // end time
  RTC.readAlarm2();
  memset(str, 0, sizeof str);
  sprintf(str, "%02u", RTC.h);
  ehour.setText(str);
  
  memset(str, 0, sizeof str);
  sprintf(str, "%02u", RTC.m);
  emin.setText(str);
}

void TimerPage::OnPageChange(const char *cmd){
  NextText shour = NextText(TIMER_START_HOUR_TEXT.PAGE, TIMER_START_HOUR_TEXT.ID, TIMER_START_HOUR_TEXT.NAME); // Start timer hour
  NextText smin = NextText(TIMER_START_MIN_TEXT.PAGE, TIMER_START_MIN_TEXT.ID, TIMER_START_MIN_TEXT.NAME); // Start timer minute
  NextText ehour = NextText(TIMER_END_HOUR_TEXT.PAGE, TIMER_END_HOUR_TEXT.ID, TIMER_END_HOUR_TEXT.NAME); // End timer hour
  NextText emin = NextText(TIMER_END_MIN_TEXT.PAGE, TIMER_END_MIN_TEXT.ID, TIMER_END_MIN_TEXT.NAME); // End timer minutes
  NextButton timer = NextButton(TIMER_TIMER_BUT.PAGE, TIMER_TIMER_BUT.ID, TIMER_TIMER_BUT.NAME); // timer button
  
  // get timer state
  uint32_t img = TIMER_TIMER_ON_BUTTON_IMG+TIMER_TIMER_OFF_BUTTON_IMG;
  timer.getBackground(img);
  if (img == TIMER_TIMER_ON_BUTTON_IMG){
    CONFIG.IS_TIMER_ENABLED = true;
  }else if (img == TIMER_TIMER_OFF_BUTTON_IMG){
    CONFIG.IS_TIMER_ENABLED = false;
  }else{
//    debugPrintln("Error get timer on/off button status from display !");
  }
  
  // start time
  char str[6];
  bool error = false;
  memset(str, 0, sizeof str);
  error |= shour.getText(str, 2) == 0;
  RTC.h = atoi(str);

  memset(str, 0, sizeof str);
  error |= smin.getText(str, 2) == 0;
  RTC.m = atoi(str);
  RTC.s = 0;
  
//  if (error){
//    debugPrintln("Error get start timer from display !");
//  }
  
  // set alarms
  if (!error){
    RTC.writeAlarm1(DS3231_ALM_HMS);
  }
  
  // end timer 
  memset(str, 0, sizeof str);
  error |= ehour.getText(str, 2) == 0;
  RTC.h = atoi(str);

  memset(str, 0, sizeof str);
  error |= emin.getText(str, 2) == 0;
  RTC.m = atoi(str);
  RTC.s = 0;
  
//  if (error){
//    debugPrintln("Error get end timer from display !");
//  }
  
  // set alarms 2
  if (!error){
    RTC.writeAlarm2(DS3231_ALM_HM);
  }  
  
  // save
  saveConfig();

  // change page
  sendCommand(cmd);
}

NextTouch** TimerPage::getCallbackListenerList(){
  return __callback_listener_list;
}

void TimerPage::Update(){ 
}
