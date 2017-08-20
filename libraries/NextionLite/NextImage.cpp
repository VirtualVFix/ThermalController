/*
 * Nextion image element
*/
#include "NextImage.h"

NextImage::NextImage(byte page_id, byte obj_id, const char *obj_name)
          :NextObject(page_id, obj_id, obj_name){
          
}

void NextImage::setImage(uint32_t number){
  setNumber(number, "pic");
}
