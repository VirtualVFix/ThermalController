#include "Config.h"
#include "HomePage.h"
#include "TimerPage.h"
#include "ClockPage.h"
#include "SettingPage.h"
#include "Setting2Page.h"
//#include "SDCard.h"

BasePage *p_current = NULL;

// settings 1 page
void settingButtonCallback(){
  p_current->OnPageChange("page 2");
  delete p_current;
  p_current = new SettingPage(homeButtonCallback, setting2ButtonCallback);
  p_current->OnPageLoad();
}

// settings 2 page
void setting2ButtonCallback(){
  p_current->OnPageChange("page 3");
  delete p_current;
  p_current = new Setting2Page(homeButtonCallback, settingButtonCallback);
  p_current->OnPageLoad();
}

// timer page
void timerButtonCallback(){
  p_current->OnPageChange("page 4");
  delete p_current;
  p_current = new TimerPage(homeButtonCallback, clockButtonCallback);
  p_current->OnPageLoad();
}

// clock page
void clockButtonCallback(){
  p_current->OnPageChange("page 5");
  delete p_current;
  p_current = new ClockPage(homeButtonCallback, timerButtonCallback);
  p_current->OnPageLoad();
}

// home page
void homeButtonCallback(){
  p_current->OnPageChange("page 1");
  delete p_current;
  p_current = new HomePage(settingButtonCallback, timerButtonCallback);
  p_current->OnPageLoad();
}

void setup(){
  // nextion init 
  nextInit();
  printMemory("setup start"); 
  
  // setup config reset pin
  pinMode(CONFIG_RESET_PIN, INPUT_PULLUP);
  byte reset = digitalRead(CONFIG_RESET_PIN);
  // reset config if CONFIG_RESET_PIN is LOW
  if (reset == LOW){
    resetConfig();
    resetWaveDataConfig(); 
  }else{ // read config
    readConfig();
    readWaveDataConfig();
  }

  p_current = new HomePage(settingButtonCallback, timerButtonCallback);
  delay(500);

  // update page
  if (getCurrentPageId() != 1){
    sendCommand("page 1");
  }
  
  p_current->InitSetup();
  p_current->OnPageLoad();

  printMemory("setup end");

//  SDCard SD = SDCard();
//  SD.write(TEMPERATURE_FILE, "TEST 1");
//  SD.read(TEMPERATURE_FILE, NULL);
}

void loop(){  
  // page loop
  nextLoop(p_current->getCallbackListenerList());
  p_current->Update();
}
