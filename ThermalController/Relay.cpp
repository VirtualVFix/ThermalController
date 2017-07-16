/* relay control module */ 
#include "Relay.h"

// constructor
Relay::Relay(){
}

void Relay::__relayON(){
  digitalWrite(RELAY_PIN, HIGH);
  LOCAL.IS_RELAY_ENABLED = true;
}

void Relay::__relayOFF(){
  digitalWrite(RELAY_PIN, LOW);
  LOCAL.IS_RELAY_ENABLED = false;
}

// update relay on/off icon
void Relay::__displayUpdateRelayIcon(){
  NextCrop _crop = NextCrop(HOME_RELAY_ACTIVE_ICON_CROP.PAGE, HOME_RELAY_ACTIVE_ICON_CROP.ID, HOME_RELAY_ACTIVE_ICON_CROP.NAME);
  _crop.setImage(LOCAL.IS_RELAY_ENABLED&CONFIG.RELAY_MAY_ENABLED ? HOME_RELAY_ON_IMG: HOME_RELAY_OFF_IMG);
}

// update relay control enable/disable icon
void Relay::__displayUpdateRelayControlIcon(){
  NextCrop _crop = NextCrop(HOME_RELAY_CONTROL_ICON_CROP.PAGE, HOME_RELAY_CONTROL_ICON_CROP.ID, HOME_RELAY_CONTROL_ICON_CROP.NAME);
  _crop.setImage(CONFIG.RELAY_MAY_ENABLED ? HOME_RELAY_ON_IMG: HOME_RELAY_OFF_IMG);
}

void Relay::UpdateIcons(){
  __displayUpdateRelayIcon();
  __displayUpdateRelayControlIcon();
}

// switch relay depends of current temperature
void Relay::__relaySwitchByTemperature(float &temp){
  if (!CONFIG.RELAY_MAY_ENABLED){
    if (LOCAL.IS_RELAY_ENABLED){
      __relayOFF();
    }
    return;
  }
  
  if (isnan(temp)){
      return;
  }
  
  if (LOCAL.IS_RELAY_ENABLED){
    if (temp >= CONFIG.RELAY_TARGET_TEMPERATURE){
      __relayOFF();
      __displayUpdateRelayIcon();
    }
  }else if (temp < (CONFIG.RELAY_TARGET_TEMPERATURE-CONFIG.RELAY_HYSTERESIS)){
    __relayON();
    __displayUpdateRelayIcon();
  }
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
  __relayOFF();
  UpdateIcons();

}

void Relay::Update(float &temp){
  __relaySwitchByTemperature(temp);
//  UpdateIcons();
}

