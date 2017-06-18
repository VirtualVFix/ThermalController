#include "ClockPage.h"

ClockPage::ClockPage(ObjectCallback homeCallback, ObjectCallback timerCallback){
  // buttons
  this->__homeButton = new NextButton(CLOCK_HOME_BUT.PAGE, CLOCK_HOME_BUT.ID, CLOCK_HOME_BUT.NAME);
  this->__timerButton = new NextButton(CLOCK_TIMER_BUT.PAGE, CLOCK_TIMER_BUT.ID, CLOCK_TIMER_BUT.NAME);

  // add button callback
  this->__homeButton->addReleaseCallback(homeCallback);
  this->__timerButton->addReleaseCallback(timerCallback);
  
  // add callback to listener
  this->__callback_listener_list[0] = this->__homeButton;
  this->__callback_listener_list[1] = this->__timerButton;
  this->__callback_listener_list[2] = NULL;
}

ClockPage::~ClockPage(){ 
  delete this->__homeButton;
  delete this->__timerButton;
}

void ClockPage::OnPageLoad(){
  NextText year = NextText(CLOCK_YEAR_TEXT.PAGE, CLOCK_YEAR_TEXT.ID, CLOCK_YEAR_TEXT.NAME);
  NextText hour = NextText(CLOCK_HOURS_TEXT.PAGE, CLOCK_HOURS_TEXT.ID, CLOCK_HOURS_TEXT.NAME);
  NextText minute = NextText(CLOCK_MINUTES_TEXT.PAGE, CLOCK_MINUTES_TEXT.ID, CLOCK_MINUTES_TEXT.NAME);
  NextText second = NextText(CLOCK_SECONDS_TEXT.PAGE, CLOCK_SECONDS_TEXT.ID, CLOCK_SECONDS_TEXT.NAME);
  NextVariable day = NextVariable(CLOCK_DAY_VAR.PAGE, CLOCK_DAY_VAR.ID, CLOCK_DAY_VAR.NAME);
  NextVariable month = NextVariable(CLOCK_MONTH_VAR.PAGE, CLOCK_MONTH_VAR.ID, CLOCK_MONTH_VAR.NAME);
  NextVariable weekday = NextVariable(CLOCK_WEEKDAY_VAR.PAGE, CLOCK_WEEKDAY_VAR.ID, CLOCK_WEEKDAY_VAR.NAME);

  // read current date and time
  RTC rtc;
  rtc.readTime();

  // time
  char str[6];
  memset(str, 0, sizeof str);
  sprintf(str, "%02u", rtc.r_time.hour);
  hour.setText(str);

  memset(str, 0, sizeof str);
  sprintf(str, "%02u", rtc.r_time.minute);
  minute.setText(str);

  memset(str, 0, sizeof str);
  sprintf(str, "%02u", rtc.r_time.second);
  second.setText(str);

  // date
  month.setValue(rtc.r_time.month);

  day.setValue(rtc.r_time.dayOfMonth);

  memset(str, 0, sizeof str);
  sprintf(str, "%d", 2000+rtc.r_time.year);
  year.setText(str);

  // click to month element to display month in text format and calc correct weekday
  char cmd[strlen(CLOCK_MONTH_TEXT.NAME)+10];
  sprintf(cmd, "click %s,0", CLOCK_MONTH_TEXT.NAME);
  sendCommand(cmd);
}

void ClockPage::OnPageChange(const char *cmd){
  // time 
  NextText hour = NextText(CLOCK_HOURS_TEXT.PAGE, CLOCK_HOURS_TEXT.ID, CLOCK_HOURS_TEXT.NAME);
  NextText minute = NextText(CLOCK_MINUTES_TEXT.PAGE, CLOCK_MINUTES_TEXT.ID, CLOCK_MINUTES_TEXT.NAME);
  NextText second = NextText(CLOCK_SECONDS_TEXT.PAGE, CLOCK_SECONDS_TEXT.ID, CLOCK_SECONDS_TEXT.NAME);

  RTC rtc;
  // hours
  char str[6];
  bool error = false;
  memset(str, 0, sizeof str);
  error |= hour.getText(str, 6) == 0;
  rtc.r_time.hour = atoi(str);
  // minutes
  memset(str, 0, sizeof str);
  error |= minute.getText(str, 6) == 0;
  rtc.r_time.minute = atoi(str);
  // seconds
  memset(str, 0, sizeof str);
  error |= second.getText(str, 6) == 0;
  rtc.r_time.second = atoi(str);

//  if (error){
//    debugPrintln("Error get time from display !");
//  }

  if (!error){
    NextVariable day = NextVariable(CLOCK_DAY_VAR.PAGE, CLOCK_DAY_VAR.ID, CLOCK_DAY_VAR.NAME);
    NextVariable month = NextVariable(CLOCK_MONTH_VAR.PAGE, CLOCK_MONTH_VAR.ID, CLOCK_MONTH_VAR.NAME);
    NextVariable weekday = NextVariable(CLOCK_WEEKDAY_VAR.PAGE, CLOCK_WEEKDAY_VAR.ID, CLOCK_WEEKDAY_VAR.NAME);
    NextText year = NextText(CLOCK_YEAR_TEXT.PAGE, CLOCK_YEAR_TEXT.ID, CLOCK_YEAR_TEXT.NAME);

    error = false;
    uint32_t num = 888;
    // day
    day.getValue(num);
    error |= num > 31;
    rtc.r_time.dayOfMonth = (byte)num;
    // weekday
    num = 888;
    weekday.getValue(num);
    error |= num > 7;
    rtc.r_time.dayOfWeek = (byte)num;
    // month
    num = 888;
    month.getValue(num);
    error |= num > 12;
    rtc.r_time.month = (byte)num;
    // year 
    memset(str, 0, sizeof str);
    error |= year.getText(str, 6) == 0;
    rtc.r_time.year = atoi(str)-2000;

//    if (error){
//      debugPrintln("Error get date from display !");
//    }
  }
  
  // set time
  if (!error){
    rtc.setTime();
  }
  
  // change page
  sendCommand(cmd);
}

NextTouch** ClockPage::getCallbackListenerList(){
  return __callback_listener_list;
}

void ClockPage::Update(){
//  printMemory("Clock update");
//  delay(500);
}
