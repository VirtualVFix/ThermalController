/*
 * Nextion image element
*/
#include "NextCrop.h"

NextCrop::NextCrop(byte page_id, byte obj_id, const char *obj_name)
         :NextObject(page_id, obj_id, obj_name){
          
}

void NextCrop::setImage(uint32_t number){
  setNumber(number, "picc");
}
