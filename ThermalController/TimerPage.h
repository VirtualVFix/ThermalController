/* timer page control module */
#ifndef __TIMERPAGE_H__
#define __TIMERPAGE_H__

#include "Config.h"

class TimerPage: public BasePage{
  public:
    // nextion touch event list
    TimerPage(ObjectCallback homeCallback, ObjectCallback clockCallback);
    ~TimerPage();

    void Update();
    void OnPageLoad();
    void OnPageChange(const char *cmd);
    NextTouch** getCallbackListenerList();

  private:
    NextButton* __homeButton;
    NextButton* __clockButton;
    NextTouch* __callback_listener_list[3];
};

#endif /* __TIMERPAGE_H__ */
