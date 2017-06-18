/* relay control module */ 
#ifndef __RELAY_H__
#define __RELAY_H__

#include "Config.h"

class Relay{//: public BaseInterface{
  bool __isRelayOn; // relay current status
  
  // relay on/off
  void __relayON();
  void __relayOFF();
  // update relay on/off icon
  void __displayUpdateRelayIcon();
  // update relay control enable/disable icon
  void __displayUpdateRelayControlIcon();
  // switch relay depends of current temperature
  void __relaySwitchByTemperature(float &temp);
  
  public: 
    Relay();
    void Setup();
    void Update(float &temp);
    // update icons
    void UpdateIcons();
    void setHysteresis(float &hyst);
    void setTargetTemperature(float &temp);
};

#endif /* __RELAY_H__ */
