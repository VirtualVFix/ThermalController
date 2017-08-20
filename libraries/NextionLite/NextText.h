/*
 * Nextion text element
*/
#ifndef __NEXTTEXT_H__
#define __NEXTTEXT_H__

#include "NextObject.h"

class NextText: public NextObject{
  public:
    NextText(byte page_id, byte obj_id, const char *obj_name);
    void setText(const char *text); // set text
    uint16_t getText(char *text, uint16_t len); // get text
    void setBackground(uint32_t number); // set background image
};

#endif
