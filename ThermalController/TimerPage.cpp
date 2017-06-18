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
}

void TimerPage::OnPageLoad(){
  
}

void TimerPage::OnPageChange(const char *cmd){
  // change page
  sendCommand(cmd);
}

NextTouch** TimerPage::getCallbackListenerList(){
  return __callback_listener_list;
}

void TimerPage::Update(){
//  printMemory("Timer update");
//  delay(500);
}

