/* clock page control module */
#ifndef __CLOCKPAGE_H__
#define __CLOCKPAGE_H__

#include "Config.h"
#include "Rtc.h"

class ClockPage: public BasePage{
  public:
    // nextion touch event list
    ClockPage(ObjectCallback homeCallback, ObjectCallback timerCallback);
    ~ClockPage();

    void Update();
    void OnPageLoad();
    void OnPageChange(const char *cmd);
    NextTouch** getCallbackListenerList();

  private:
    NextButton* __homeButton;
    NextButton* __timerButton;
    NextTouch* __callback_listener_list[3];
};

#endif /* __CLOCKPAGE_H__ */
