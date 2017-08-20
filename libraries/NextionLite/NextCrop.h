/*
 * Nextion image element
*/
#ifndef __NEXTCROP_H__
#define __NEXTCROP_H__

#include "NextObject.h"

class NextCrop: public NextObject{
  public:
    NextCrop(byte page_id, byte obj_id, const char *obj_name);
    void setImage(uint32_t number); // set image
};

#endif
