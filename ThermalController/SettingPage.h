/* setting 1 page control module */
#ifndef __SETTINGPAGE_H__
#define __SETTINGPAGE_H__

#include "Config.h"

class SettingPage: public BasePage{
  public:
    SettingPage(ObjectCallback homeCallback, ObjectCallback settingCallback);
    ~SettingPage();
    
    void Update();
    void OnPageLoad();
    void OnPageChange(const char *cmd);
    
    NextTouch** getCallbackListenerList();

  private:
    // nextion touch event list
    NextTouch* __callback_listener_list[3];
    NextButton* __homeButton;
    NextButton* __settingButton;
};

#endif /* __SETTINGPAGE_H__ */
