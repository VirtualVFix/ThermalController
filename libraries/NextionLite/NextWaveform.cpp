/*
 * Nextion wave form element
*/
#include "NextWaveform.h"

NextWaveform::NextWaveform(byte page_id, byte obj_id, const char *obj_name)
             :NextObject(page_id, obj_id, obj_name){
          
}

void NextWaveform::addValue(byte channel, byte number){
  char str[15] = "";
  if (channel > 3){
    //debugPrintln("WRONG CHANNEL NUMBER FOR WAVEFORM");
    return;
  }
  sprintf(str, "add %u,%u,%u", this->getObjectId(), channel, number);
  sendCommand("");
  sendCommand(str);
}
