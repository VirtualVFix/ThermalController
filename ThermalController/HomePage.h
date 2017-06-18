/* home page control module */
#ifndef __HOMEPAGE_H__
#define __HOMEPAGE_H__

#include "Rtc.h"
#include "Relay.h"
#include "Sensor.h"
#include "Config.h"

class HomePage: public BasePage{
  public:
    HomePage(ObjectCallback settingsCallback, ObjectCallback timerCallback);
    ~HomePage();
    void InitSetup();
    void OnPageLoad();
    void OnPageChange(const char *cmd);
    void Update();
    NextTouch** getCallbackListenerList();

  private:
    // nextion touch event list
    NextTouch* __callback_listener_list[3]; 
    // current time stamp
    unsigned long __time_update_timestamp;
    unsigned long __sensor_update_timestamp;
    // relay 
    Relay __relay;
    // rtc
    RTC __rtc;
    // thermal sensor 
    Sensor __sensor;
    // buttons on home page
    NextButton* __settingButton;
    NextButton* __timerButton;
};

#endif
