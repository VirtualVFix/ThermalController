/*
 * Nextion base class 
*/
#include "NextTouch.h"

NextTouch::NextTouch(byte page_id, byte obj_id, const char *obj_name)
          :NextBase(page_id, obj_id, obj_name){
    this->__pressCallback = NULL;
    this->__releaseCallback = NULL;
}

void NextTouch::addPressCallback(ObjectCallback call){
  this->__pressCallback = call;
}

void NextTouch::addReleaseCallback(ObjectCallback call){
  this->__releaseCallback = call;
}

// press callback
void NextTouch::pressCallback(){
  if (this->__pressCallback){
    this->__pressCallback();
  }
}

// release calback
void NextTouch::releaseCallback(){
  if (this->__releaseCallback){
    this->__releaseCallback();
  }
}
