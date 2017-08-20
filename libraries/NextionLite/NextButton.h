/*
 * Nextion button element
*/
#ifndef __NEXTBUTTON_H__
#define __NEXTBUTTON_H__

#include "NextObject.h"
#include "NextTouch.h"

class NextButton: public NextObject, public NextTouch{
  public:
    NextButton(byte page_id, byte obj_id, const char *obj_name);
    void setBackground(uint32_t number);
    void getBackground(uint32_t &number);
};

#endif
