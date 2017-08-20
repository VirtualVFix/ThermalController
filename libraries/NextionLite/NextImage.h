/*
 * Nextion image element
*/
#ifndef __NEXTIMAGE_H__
#define __NEXTIMAGE_H__

#include "NextObject.h"

class NextImage: public NextObject{
  public:
    NextImage(byte page_id, byte obj_id, const char *obj_name);
    void setImage(uint32_t number); // set image
};

#endif
