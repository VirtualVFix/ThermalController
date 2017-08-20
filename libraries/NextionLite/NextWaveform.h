/*
 * Nextion wave form element
*/
#ifndef __NEXTWAVEFORM_H__
#define __NEXTWAVEFORM_H__

#include "NextObject.h"

class NextWaveform: public NextObject{
  public:
    NextWaveform(byte page_id, byte obj_id, const char *obj_name);
    void addValue(byte channel, byte number); // add value to waveform
};

#endif
