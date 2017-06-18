/* relay control module */ 
#include "Relay.h"

// constructor
Relay::Relay(){
  __isRelayOn = false;
}

void Relay::__relayON(){
  digitalWrite(RELAY_PIN, HIGH);
  __isRelayOn = true;
}
void Relay::__relayOFF(){
  digitalWrite(RELAY_PIN, LOW);
  __isRelayOn = false;
}

// update relay on/off icon
void Relay::__displayUpdateRelayIcon(){
  NextCrop _crop = NextCrop(HOME_RELAY_ACTIVE_ICON_CROP.PAGE, HOME_RELAY_ACTIVE_ICON_CROP.ID, HOME_RELAY_ACTIVE_ICON_CROP.NAME);
  _crop.setImage(__isRelayOn&CONFIG.RELAY_MAY_ENABLED ? HOME_RELAY_ON_IMG: HOME_RELAY_OFF_IMG);
}

// switch relay depends of current temperature
void Relay::__relaySwitchByTemperature(float &temp){
  if (!CONFIG.RELAY_MAY_ENABLED){
    return;
  }
  
  if (__isRelayOn){
    if (temp >= CONFIG.RELAY_TARGET_TEMPERATURE){
      __relayOFF();
      __displayUpdateRelayIcon();
    }
  }else if (temp < (CONFIG.RELAY_TARGET_TEMPERATURE-CONFIG.RELAY_HYSTERESIS)){
    __relayON();
    __displayUpdateRelayIcon();
  }
}

// update relay control enable/disable icon
void Relay::__displayUpdateRelayControlIcon(){
  NextCrop _crop = NextCrop(HOME_RELAY_CONTROL_ICON_CROP.PAGE, HOME_RELAY_CONTROL_ICON_CROP.ID, HOME_RELAY_CONTROL_ICON_CROP.NAME);
  _crop.setImage(CONFIG.RELAY_MAY_ENABLED ? HOME_RELAY_ON_IMG: HOME_RELAY_OFF_IMG);
}

void Relay::setHysteresis(float &hyst){
  CONFIG.RELAY_HYSTERESIS = hyst;
}

void Relay::setTargetTemperature(float &temp){
  CONFIG.RELAY_TARGET_TEMPERATURE = temp;
}

// init setup
void Relay::Setup(){
  pinMode(RELAY_PIN, OUTPUT);
  UpdateIcons();
}

void Relay::UpdateIcons(){
  __displayUpdateRelayControlIcon();
  __displayUpdateRelayIcon();
}

void Relay::Update(float &temp){
  __relaySwitchByTemperature(temp);
}

