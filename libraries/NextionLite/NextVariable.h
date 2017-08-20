/*
 * Nextion variable element
*/
#ifndef __NEXTVARIABLE_H__
#define __NEXTVARIABLE_H__

#include "NextObject.h"

class NextVariable: public NextObject{
  public:
    NextVariable(byte page_id, byte obj_id, const char *obj_name);
    void setText(const char *text); // set text
    uint16_t getText(char *text, uint16_t len); // get text
    void setValue(uint32_t number); // set number value
    void getValue(uint32_t &number); // get number value
};

#endif
