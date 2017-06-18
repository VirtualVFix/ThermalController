/* setting 1 page control module */
#ifndef __SETTING2PAGE_H__
#define __SETTING2PAGE_H__

#include "Config.h"

class Setting2Page: public BasePage{
  public:
    Setting2Page(ObjectCallback homeCallback, ObjectCallback settingCallback);
    ~Setting2Page();
    
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

#endif /* __SETTING2PAGE_H__ */
